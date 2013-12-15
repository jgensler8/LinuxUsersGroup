#!/bin/awk
{
  for( i=0; i<NR; ++i){
    if( 0 != find( $i, "shard2") ){
      #echo the randid into a file
    }
  }
}
