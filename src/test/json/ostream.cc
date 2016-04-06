// Copyright (c) 2016 Dr. Colin Hirsch
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#include "test.hh"

#include <sstream>

#include <tao/json.hh>

namespace tao
{
   namespace json
   {
      void test_simple( const value & v, const std::string & s )
      {
         TEST_ASSERT( to_string( v ) == s );
         std::ostringstream oss;
         oss << v;
         TEST_ASSERT( oss.str() == s );
      }

      void test_pretty( const value & v, const std::string & s )
      {
         std::ostringstream oss;
         oss << std::setw( 2 );
         oss << v;
         TEST_ASSERT( oss.str() == s );
      }

      void unit_test()
      {
         test_simple( value( nullptr ), "null" );
         test_simple( value( true ), "true" );
         test_simple( value( false ), "false" );
         test_simple( value( 42 ), "42" );
         test_simple( value( 42.1 ), "42.1" );
         test_simple( value( "foo" ), "\"foo\"" );
         test_simple( empty_array, "[]" );
         test_simple( value::array(), "[]" );
         test_simple( value::array( 1 ), "[1]" );
         test_simple( value::array( 1, 2, 3 ), "[1,2,3]" );
         test_simple( empty_object, "{}" );
         //         test_simple( {}, "{}" );  Producess null.
         test_simple( { { "foo", 42 } }, "{\"foo\":42}" );
         test_simple( { { "foo", 42 }, { "bar", 43 } }, "{\"bar\":43,\"foo\":42}" );

         test_pretty( value( nullptr ), "null" );
         test_pretty( value( true ), "true" );
         test_pretty( value( false ), "false" );
         test_pretty( value( 42 ), "42" );
         test_pretty( value( 42.1 ), "42.1" );
         test_pretty( value( "foo" ), "\"foo\"" );
         test_pretty( empty_array, "[]" );
         test_pretty( value::array(), "[]" );
         test_pretty( value::array( 1 ), "[\n  1\n]" );
         test_pretty( value::array( 1, 2, 3 ), "[\n  1,\n  2,\n  3\n]" );
         test_pretty( empty_object, "{}" );
         //         test_pretty( {}, "{}" );  // Produces null.
         test_pretty( { { "foo", 42 } }, "{\n  \"foo\": 42\n}" );
         test_pretty( { { "foo", 42 }, { "bar", 43 } }, "{\n  \"bar\": 43,\n  \"foo\": 42\n}" );
      }

   } // json

} // tao

#include "main.hh"