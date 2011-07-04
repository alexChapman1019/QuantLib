/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2010 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file fdm2dblackscholessolver.hpp
*/

#ifndef quantlib_fdm_2d_black_scholes_solver_hpp
#define quantlib_fdm_2d_black_scholes_solver_hpp

#include <ql/handle.hpp>
#include <ql/patterns/lazyobject.hpp>
#include <ql/experimental/finitedifferences/fdmsolverdesc.hpp>
#include <ql/experimental/finitedifferences/fdmbackwardsolver.hpp>

namespace QuantLib {

    class Fdm2DimSolver;
    class GeneralizedBlackScholesProcess;

    class Fdm2dBlackScholesSolver : public LazyObject {
      public:
        Fdm2dBlackScholesSolver(
            const Handle<GeneralizedBlackScholesProcess>& p1,
            const Handle<GeneralizedBlackScholesProcess>& p2,
            const Real correlation,
            const FdmSolverDesc& solverDesc,
            const FdmSchemeDesc& schemeDesc = FdmSchemeDesc::Hundsdorfer());

        Real valueAt(Real x, Real y) const;
        Real thetaAt(Real x, Real y) const;

        Real deltaXat(Real x, Real y) const;
        Real deltaYat(Real x, Real y) const;
        Real gammaXat(Real x, Real y) const;
        Real gammaYat(Real x, Real y) const;

      protected:
        void performCalculations() const;

      private:
        const Handle<GeneralizedBlackScholesProcess> p1_;
        const Handle<GeneralizedBlackScholesProcess> p2_;
        const Real correlation_;
        const FdmSolverDesc solverDesc_;
        const FdmSchemeDesc schemeDesc_;

        mutable boost::shared_ptr<Fdm2DimSolver> solver_;
    };
}

#endif