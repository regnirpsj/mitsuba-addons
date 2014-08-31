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
  
  // functions, internal

} // namespace {

namespace mitsuba {
  
  // variables, exported
  
  // functions, exported

  dcomplex::dcomplex(Properties const& p)
    : SamplingIntegrator(p),
      color_            (p.getSpectrum("color",      Spectrum(1.0f))),
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
  dcomplex::Li(RayDifferential const& r, RadianceQueryRecord& rec) const
  {
    // primary intersection
    rec.rayIntersect(r);
    
    while (rec.its.isValid() && ((rec.depth <= max_depth_) || (0 > max_depth_))) {
      ++rec.depth;
      
      // ray recursion
      rec.scene->rayIntersect(Ray(rec.its.p, r.d, r.time), rec.its);
    }
    
    return Spectrum(rec.depth) * color_;
  }
  
  MTS_IMPLEMENT_CLASS_S(dcomplex, false, SamplingIntegrator);
  MTS_EXPORT_PLUGIN    (dcomplex, "A depth-complexity integrator");
  
} // namespace mitsuba {
