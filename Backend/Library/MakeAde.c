#include "world.h"


/**************************************************************************/
/* GLOBAL **************          MakeAde          ************************/
/**************************************************************************/
/* PURPOSE: MAKE AN ARTIFICAIL DEPENDENCE EDGE AND INITIALIZE IT.  THEN   */
/*          LINK THE EDGE INTO ITS DESTINATION NODE'S ADE IMPORT LIST AND */
/*          SOURCE NODE'S ADE EXPORT LIST.                                */
/*									  */
/*	    IF FULLY ORDERED, DO NOTHING.  			          */
/**************************************************************************/

void MakeAde( snode, dnode )
int snode;
int dnode;
{
  if ( !FullyOrdered ) {
    register PADE  a;
    register PNODE src;
    register PNODE dst;

    dst = FindNode( dnode, IFUndefined );
    src = FindNode( snode, IFUndefined );

    a          = AdeAlloc( src, dst, LOW_PRI );
    a->if1line = line;

    LinkAdeImport( dst, a );
    LinkAdeExport( src, a );
  }
}

/* $Log$
/* Revision 1.1.1.1  2000/12/31 17:58:27  patmiller
/* Well, here is the first set of big changes in the distribution
/* in 5 years!  Right now, I did a lot of work on configuration/
/* setup (now all autoconf), breaking out the machine dependent
/* #ifdef's (with a central acconfig.h driven config file), changed
/* the installation directories to be more gnu style /usr/local
/* (putting data in the /share/sisal14 dir for instance), and
/* reduced the footprint in the top level /usr/local/xxx hierarchy.
/*
/* I also wrote a new compiler tool (sisalc) to replace osc.  I
/* found that the old logic was too convoluted.  This does NOT
/* replace the full functionality, but then again, it doesn't have
/* 300 options on it either.
/*
/* Big change is making the code more portably correct.  It now
/* compiles under gcc -ansi -Wall mostly.  Some functions are
/* not prototyped yet.
/*
/* Next up: Full prototypes (little) checking out the old FLI (medium)
/* and a new Frontend for simpler extension and a new FLI (with clean
/* C, C++, F77, and Python! support).
/*
/* Pat
/*
/*
 * Revision 1.2  1994/07/13  18:08:37  denton
 * Removed BAD from IFX.h and fix MakeAde to use LOW_PRI (it incorrectly used LOW)
 *
 * Revision 1.1  1993/01/21  23:29:32  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
