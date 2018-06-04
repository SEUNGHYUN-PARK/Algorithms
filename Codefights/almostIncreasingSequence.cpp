bool almostIncreasingSequence(std::vector<int> sequence) {
int none_increasing_sequence = 0;

vector<int>::iterator it = sequence.begin();
while ( it != ( sequence.end() - 1 ) )
{
	if ( *it < *( it + 1 ) )
  {
		it++;
	}
  else
  {
		none_increasing_sequence++;
		if ( it == sequence.begin() )
    {
			sequence.erase( it );
		}
    else if ( ( *it > *( it - 1 ) ) && ( *( it + 1 ) > *( it - 1 ) ) ) {
			sequence.erase( it );
		}
    else {
			sequence.erase( it + 1 );
		}
		it = sequence.begin();
	}

	if ( none_increasing_sequence >= 2 ) {
		return false;
	}
}
  return true;
}
