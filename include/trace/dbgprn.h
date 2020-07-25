#ifndef DBGPRN_H_INCLUDED
#define DBGPRN_H_INCLUDED

void myDbg ( const char* function, int line, const char* message );

const char* myDbgGetStrInt ( const char* name, int val );

const char* myDbgGetStrStr ( const char* name, const char* val );

#if defined(DBGPRN_ENABLED)

  #define LGGM_TRACE() do{ myDbg(__FUNCTION__, __LINE__, "trace"); }while(0);
  #define LGGM_CALL_IN() do{ myDbg(__FUNCTION__, __LINE__, "->"); }while(0);
  #define LGGM_CALL_OUT() do{ myDbg(__FUNCTION__, __LINE__, "<-"); }while(0);
  #define LGGM_PRINT_MSG(txt) do{ myDbg(__FUNCTION__, __LINE__, txt); }while(0);
  #define LGGM_PRINT_INT(var) do{ myDbg(__FUNCTION__, __LINE__, myDbgGetStrInt(#var, var)); }while(0);
  #define LGGM_PRINT_STR(var) do{ myDbg(__FUNCTION__, __LINE__, myDbgGetStrStr(#var, var)); }while(0);

#else

  #define LGGM_TRACE()
  #define LGGM_CALL_IN()
  #define LGGM_CALL_OUT()
  #define LGGM_PRINT_MSG(txt)
  #define LGGM_PRINT_INT(var)
  #define LGGM_PRINT_STR(var)

#endif

#endif /* DBGPRN_H_INCLUDED */
