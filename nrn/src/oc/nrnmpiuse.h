/* src/oc/nrnmpiuse.h.  Generated from nrnmpiuse.h.in by configure.  */
#ifndef usenrnmpi_h
#define usenrnmpi_h

/* define to 1 if you want MPI specific features activated */
/* #undef NRNMPI */

/* define to 1 if you want parallel distributed cells (and gap junctions) */
/* #undef PARANEURON */

/* define to 1 if you want the MUSIC - MUlti SImulation Coordinator */
/* #undef NRN_MUSIC */

/* define to the dll path if you want to load automatically */
/* #undef DLL_DEFAULT_FNAME */

/* define if needed */
/* #undef ALWAYS_CALL_MPI_INIT */

/* Number of times to retry a failed open */
/* #undef FILE_OPEN_RETRY */

/* define if IBM BlueGene L or P (activates BGLCheckPoint functionality) */
/* #undef BLUEGENE */

/* define if IBM BlueGene/P */
/* #undef BLUEGENEP */

/* define BlueGene with checkpointing */
/* #undef BLUEGENE_CHECKPOINT */

/* define to 1 if you want the framework supporting BlueGene/P style direct dma transfer of spikes */
/* #undef BGPDMA */

#endif
