// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  integrators/dcomplex.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "dcomplex.hpp"

// includes, system

//#include <>

// includes, project

//#include <>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  mitsuba::Float          dflt_color_values[SPECTRUM_SAMPLES] = { 0.2f, 0.5f, 0.2f };
  mitsuba::Spectrum const dflt_color(dflt_color_values);
  
  // functions, internal

} // namespace {

namespace mitsuba {
  
  // variables, exported
  
  // functions, exported

  dcomplex::dcomplex(Properties const& p)
    : SamplingIntegrator(p),
      color_            (p.getSpectrum("color", dflt_color)),
      max_depth_        (p.getInteger ("max_depth", -1))
  {}
  
  dcomplex::dcomplex(Stream* s, InstanceManager* m)
    : SamplingIntegrator(s, m),
      color_            (Spectrum(s)),
      max_depth_        (s->readInt())
  {}

  /* virtual */ void
  dcomplex::serialize(Stream* s, InstanceManager* m) const
  {
    SamplingIntegrator::serialize(s, m);
    color_.serialize(s);
    s->writeInt(max_depth_);
  }
  
  /* virtual */ Spectrum
  dcomplex::Li(RayDifferential const& a, RadianceQueryRecord& b) const
  {
    Spectrum             result(1.0f);
    unsigned             depth (0);
    RadianceQueryRecord& rec   (b);

    // primary intersection
    rec.rayIntersect(a);
    
    while (rec.its.isValid() && ((rec.depth <= max_depth_) || (0 > max_depth_))) {
      ++depth;

      // ray recursion
      rec.scene->rayIntersect(Ray(rec.its.p, a.d, a.time), rec.its);
    }
    
    if (0 < depth) {
      result = Spectrum((depth / Float(depth + 1)) - 0.45) * color_;
    }
    
    return result;
  }
  
  MTS_IMPLEMENT_CLASS_S(dcomplex, false, SamplingIntegrator);
  MTS_EXPORT_PLUGIN    (dcomplex, "A depth-complexity integrator");
  
} // namespace mitsuba {
