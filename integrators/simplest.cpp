// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  integrators/simplest.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "simplest.hpp"

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

  simplest::simplest(Properties const& p)
    : SamplingIntegrator(p),
      color_            (p.getSpectrum("color", Spectrum(1.0f)))
  {}
  
  simplest::simplest(Stream* s, InstanceManager* m)
    : SamplingIntegrator(s, m),
      color_            (Spectrum(s))
  {}

  /* virtual */ void
  simplest::serialize(Stream* s, InstanceManager* m) const
  {
    SamplingIntegrator::serialize(s, m);
    color_.serialize(s);
  }
  
  /* virtual */ Spectrum
  simplest::Li(RayDifferential const& a, RadianceQueryRecord& b) const
  {
    Spectrum result(1.0f);

    if (b.rayIntersect(a)) {
      result *= color_;
    }
    
    return result;
  }
  
  MTS_IMPLEMENT_CLASS_S(simplest, false, SamplingIntegrator);
  MTS_EXPORT_PLUGIN    (simplest, "A super simple integrator");
  
} // namespace mitsuba {
