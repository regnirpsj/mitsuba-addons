// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  integrators/dcomplex.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_MITSUBA_ADDONS_INTEGRATORS_DCOMPLEX_HPP)

#define UKACHULLDCS_MITSUBA_ADDONS_INTEGRATORS_DCOMPLEX_HPP

// includes, system

#include <mitsuba/render/scene.h>

// includes, project

//#include <>

namespace mitsuba {
  
  // types, exported (class, enum, struct, union, typedef)

  class  dcomplex : public  SamplingIntegrator {
    
  public:

    MTS_DECLARE_CLASS();

    dcomplex(Properties const&);
    dcomplex(Stream*, InstanceManager*);

    virtual void     serialize(Stream*, InstanceManager*) const;
    virtual Spectrum Li(RayDifferential const&, RadianceQueryRecord&) const;

  private:

    Spectrum color_;
    signed   max_depth_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace mitsuba {

#endif // #if !defined(UKACHULLDCS_MITSUBA_ADDONS_INTEGRATORS_DCOMPLEX_HPP)
