#include "world.h"


/**************************************************************************/
/* GLOBAL **************     AreNodesDependent     ************************/
/**************************************************************************/
/* PURPOSE: RETURN TRUE IF NODE n1 EXPORTS A VALUE USED BY NODE n2, ELSE  */
/*          RETURN FALSE.                                                 */
/**************************************************************************/

int AreNodesDependent( n1, n2 )
PNODE n1;
PNODE n2;
{
  register PEDGE e;

  for ( e = n1->exp; e != NULL; e = e->esucc ) {
    if ( e->dst == n2 )
      return( TRUE );

    if ( IsGraph( e->dst ) )
      continue;

    if ( AreNodesDependent( e->dst, n2 ) )
      return( TRUE );
  }

  return( FALSE );
}

/* $Log$
/* Revision 1.1.1.1  2000/12/31 17:58:10  patmiller
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
 * Revision 1.1  1993/04/16  18:59:40  miller
 * Name shortening to keep the archiver from truncating names in Backend/Library
 * Since some names were changed, other files were affected.  All names in the
 * library now start with no more than 13 (unique) characters.
 *
 * Revision 1.1  1993/01/21  23:27:45  miller
 * Initial version of the IFX library.  It replaces the if[12]build.c
 * read.c timer.c util.c and write.c and if[12].h files from the
 * backend phases.
 * */
