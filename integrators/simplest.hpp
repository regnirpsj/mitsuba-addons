// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  integrators/simplest.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_MITSUBA_ADDONS_INTEGRATORS_SIMPLEST_HPP)

#define UKACHULLDCS_MITSUBA_ADDONS_INTEGRATORS_SIMPLEST_HPP

// includes, system

#include <mitsuba/render/scene.h>

// includes, project

//#include <>

namespace mitsuba {
  
  // types, exported (class, enum, struct, union, typedef)

  class  simplest : public  SamplingIntegrator {
    
  public:

    MTS_DECLARE_CLASS();

    simplest(Properties const&);
    simplest(Stream*, InstanceManager*);

    virtual void     serialize(Stream*, InstanceManager*) const;
    virtual Spectrum Li(RayDifferential const&, RadianceQueryRecord&) const;

  private:

    Spectrum color_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace mitsuba {

#endif // #if !defined(UKACHULLDCS_MITSUBA_ADDONS_INTEGRATORS_SIMPLEST_HPP)
