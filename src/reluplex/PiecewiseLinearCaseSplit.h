/*********************                                                        */
/*! \file PiecewiseLinearCaseSplit.h
** \verbatim
** Top contributors (to current version):
**   Guy Katz
** This file is part of the Marabou project.
** Copyright (c) 2016-2017 by the authors listed in the file AUTHORS
** in the top-level source directory) and their institutional affiliations.
** All rights reserved. See the file COPYING in the top-level source
** directory for licensing information.\endverbatim
**/

#ifndef __PiecewiseLinearCaseSplit_h__
#define __PiecewiseLinearCaseSplit_h__

#include "Equation.h"

class PiecewiseLinearCaseSplit
{
public:
    struct Bound
    {
    public:
        Bound( unsigned variable, bool upperBound, double newBound )
            : _variable( variable )
            , _upperBound( upperBound )
            , _newBound( newBound )
        {
        }

        /*
          The variable whos bound is being tightened.
        */
        unsigned _variable;

        /*
          True iff the upper bound is being tightened.
        */
        bool _upperBound;

        /*
          Value of the new bound.
        */
        double _newBound;
    };

    /*
      Store information regarding a bound tightening.
    */
    void storeBoundTightening( const Bound &bound );
    List<PiecewiseLinearCaseSplit::Bound> getBoundTightenings() const;

    /*
      Store information regarding a new equation to be added.
    */
    void setEquation( const Equation &equation );
    Equation getEquation() const;

private:
    /*
      Bound tightening information.
    */
    List<PiecewiseLinearCaseSplit::Bound> _bounds;

    /*
      The equation that needs to be added.
    */
    Equation _equation;
};

#endif // __PiecewiseLinearCaseSplit_h__

//
// Local Variables:
// compile-command: "make -C .. "
// tags-file-name: "../TAGS"
// c-basic-offset: 4
// End:
//
