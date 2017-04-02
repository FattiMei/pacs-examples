#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef vector<int> Vector;


int main( int argc, char* argv[] )
{
  Vector values(10,10);
  
  // Insert four 55
  values[2] = 55;
  values[4] = 55;
  values[6] = 55;
  //  values[9] = 55;

  // Print the vector
  for ( auto i: values )
    cout << i << endl;

  // Search the first 55
  Vector::iterator it1 = find( values.begin(), values.end(), 55 );
  
  // Determine if it is found, then search the second one
  if ( it1 != values.end() )
  {
      Vector::iterator it2 = find( ++it1, values.end(), 55 );

      // Determine if the second 55 is found, then search the third
      if ( it2 != values.end() )
      {
	  it1 = find( ++it2, values.end(), 55 );
	  
	  // Determine if the third 55 is found
	  if( it1 != values.end() )
	  {
	      cout << "Three values of 55 found!!\n" 
	           << "Position of the third 55 is " 
		   << distance( values.begin(), it1 ) 
		   << endl;
	  }
	  else
	  {
	      cerr << "Third value of 55 not found" << endl;
	      abort();
	  }
      }
      else
      {
      	  cerr << "Second value of 55 not found" << endl;
	  abort();
      }
      // Search the second 55
  }
  else
  {
      cerr << "First value of 55 not found" << endl;
      abort();
  }
  
  return 0;
}

