// #include <iostream>
// using namespace std;

// void min_heapify(int *a,int i,int n)
// {
//     int j, temp;
//     temp = a[i];
//     j = 2 * i;
//     while (j <= n)
//     {
//         if (j < n && a[j+1] < a[j])
//             j = j + 1;
//         if (temp < a[j])
//             break;
//         else if (temp >= a[j])
//         {
//             a[j/2] = a[j];
//             j = 2 * j;
//         }
//     }
//     a[j/2] = temp;
//     return;
// }

// void build_minheap(int *a, int n)
// {
//     int i;
//     for(i = n/2; i >= 1; i--)
//         min_heapify(a,i,n);
// }

// int find1(int b[],int x,int n){
//     for(int i=1;i<=n;i++){
//         if(b[i]==x)
//             return i;
//     }
// }

// int main()
// {
//     int n, i, x,z,temp;
//     cin>>n;
//     int a[n+1],b[n+1];
//     for (i = 1; i <= n; i++)
//     {
//         cin>>a[i];
//         b[i]=a[i];
//     }
//     build_minheap(a, n);
//     int flag=0;
//     for (i =n; i >0; i--){   
//         if(a[i]!=b[i]){
//             temp=b[i]; 
//             z=find1(b,a[i],n);
//             b[i]=b[z];
//             b[z]=temp;
//             cout<<z-1<<" "<<i-1<<endl;
//             flag=1;
//         }
//     }
//     if(flag==0)cout<<0<<endl;
//     return 0;
// }
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder
{
private:
  vector< int > data_;
  vector< pair< int, int > > swaps_;

  void WriteResponse() const
  {
    cout << swaps_.size() << "\n";
    for ( size_t i = 0; i < swaps_.size(); ++i )
    {
      cout << swaps_[ i ].first << " " << swaps_[ i ].second << "\n";
    }
  }

  int LeftChild( int i ) { return 2 * i + 1; }

  int RightChild( int i ) { return 2 * i + 2; }

  int Parent( int i )
  {
    if ( i == 0 )
      return 0;
    else
      return ( i - 1 ) / 2;
  }

  void ReadData()
  {
    int n;
    cin >> n;
    data_.resize( n );
    for ( int i = 0; i < n; ++i )
      cin >> data_[ i ];
  }

  void SiftUp( int i )
  {
    int c = i;
    while ( c > 0 && data_[ Parent( c ) ] > data_[ c ] )
    {
      swaps_.push_back( make_pair( Parent( c ), c ) );
      swap( data_[ Parent( c ) ], data_[ c ] );
      c = Parent( c );
    }
  }

  void SiftDown( int i )
  {
    int size = data_.size() - 1;
    int maxIndex = i;
    int left = LeftChild( i );
    if ( left <= size && data_[ left ] < data_[ maxIndex ] )
    {
      maxIndex = left;
    }

    int right = RightChild( i );
    if ( right <= size && data_[ right ] < data_[ maxIndex ] )
    {
      maxIndex = right;
    }

    if ( i != maxIndex )
    {
      swaps_.push_back( make_pair( i, maxIndex ) );
      swap( data_[ i ], data_[ maxIndex ] );
      SiftDown( maxIndex );
    }
  }

  void GenerateSwaps()
  {
    swaps_.clear();
    int n = data_.size();
    int mid = n / 2;
    for ( int i = mid; i >= 0; --i )
    {
      SiftDown( i );
    }

    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    /* for (size_t i = 0; i < data_.size(); ++i) */
    /*   for (size_t j = i + 1; j < data_.size(); ++j) { */
    /*     if (data_[i] > data_[j]) { */
    /*       swap(data_[i], data_[j]); */
    /*       swaps_.push_back(make_pair(i, j)); */
    /*     } */
    /*   } */
  }

public:
  void Solve()
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio( false );
  HeapBuilder heap_builder;
  heap_builder.Solve();

  return 0;
}