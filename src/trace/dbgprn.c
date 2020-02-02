#include <trace/dbgprn.h>

#include <time.h>
#include <stdio.h>

void myDbg ( const char* function, int line, const char* message )
{
  static const char* s_File = "/var/tmp/LKTRGL_TRACE.log";
  FILE* out = NULL;

  if ( ( out = fopen ( s_File, "at" ) ) )
  {
    char timeStamptBuff[64];
    time_t result = time ( NULL );
    struct tm* locTime = localtime ( &result );
    strftime ( timeStamptBuff, sizeof timeStamptBuff, "%Y-%m-%d %H:%M:%S", locTime );
    fprintf ( out, "%s %s:%d %s\n",
              timeStamptBuff,
              function,
              line,
              message );
    fclose ( out );
  }
}

const char* myDbgGetStrInt ( const char* name, int val )
{
  enum { bufflen = 128};
  static char buff[bufflen];
  sprintf ( buff, "%s=%d", name, val );
  return buff;
}

const char* myDbgGetStrStr ( const char* name, const char* val )
{
  enum { bufflen = 1024};
  static char buff[bufflen];
  sprintf ( buff, "%s='%s'", name, val );
  return buff;
}
