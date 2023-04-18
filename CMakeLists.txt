cmake_minimum_required( VERSION 3.13 )

# #
# # This must go before project() (gcc / g++ / gdb)
# #
# set(CMAKE_C_COMPILER "gcc")
# set(CMAKE_C_FLAGS_DEBUG "-g")
# set(CMAKE_C_FLAGS "-fno-inline")
# set(CMAKE_C_FLAGS "-fno-inline-functions")
#
# set(CMAKE_CXX_COMPILER "g++")
# set(CMAKE_CXX_FLAGS_DEBUG "-g")
# set(CMAKE_CXX_FLAGS "-fno-inline")
# set(CMAKE_CXX_FLAGS "-fno-inline-functions")

#
# This must go before project() (clang / clang++ / lldb)
#
# set(CMAKE_INSTALL_RPATH "/usr/local/lib")
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# set(CMAKE_PREFIX_PATH "/usr/local/lib")
# set(CMAKE_PREFIX_PATH "/usr/local/Cellar/curlpp")
set(CMAKE_C_COMPILER "clang")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS "-fno-inline")
set(CMAKE_C_FLAGS "-fno-inline-functions")

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS "-fno-inline")
set(CMAKE_CXX_FLAGS "-fno-inline-functions")

# include_directories(/usr/local/opt/curlpp/include/)
# project( Algos_Collection )
#
# set(ENV{PKG_CONFIG_PATH} "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig")
# set( CMAKE_CXX_STANDARD 17 )
#
# set(CURL_LIBRARY "-lcurl")
# find_package(CURL REQUIRED)
#
# # CODING ASSESSMENT
# add_executable(CodingAssessment CodingAssessment.cpp)
# target_link_libraries(CodingAssessment PRIVATE CURL::libcurl)
# # add_executable(Algos_Collection CodingAssessment.cpp )


cmake_minimum_required(VERSION 3.13)
project(Algos_Collection)

set(CMAKE_CXX_STANDARD 17)

# # Find libcurl
# find_package(CURL REQUIRED)
#
# # Include libcurl headers
# include_directories(${CURL_INCLUDE_DIR})
#
# # Add the executable target
# add_executable(CodingAssessment CodingAssessment.cpp)
#
# # Link against libcurl
# target_link_libraries(CodingAssessment ${CURL_LIBRARIES})





# include_directories(${CURL_INCLUDE_DIR})
# target_link_libraries(Algos_Collection ${CURL_LIBRARIES})
# include(FindPkgConfig)
# pkg_check_modules(CURLPP REQUIRED curlpp)
# target_link_libraries(Algos_Collection ${CURLPP_LDFLAGS})

# # Find curlpp
# find_package(curlpp REQUIRED)
#
# # Link against curlpp
# target_link_libraries(CodingAssessment curlpp)
#
# include(FindPkgConfig)
# pkg_check_modules(CURLPP REQUIRED curlpp)
#
# add_executable(Algos_Collection
#     CodingAssessment.cpp
# )
# target_link_libraries(Algos_Collection
#     ${CURLPP_LDFLAGS}
# )

# Find the curlpp library
find_library(CURLPP_LIB curlpp)

# Set the include path for curlpp
include_directories(/usr/local/opt/curlpp/include)

# Add your project files
add_executable(CodingAssessment CodingAssessment.cpp)

# Link against the curlpp library
target_link_libraries(CodingAssessment ${CURLPP_LIB})


# add_executable(SeparateChainingHashST1 SeparateChainingHashST1.cpp)
# add_executable(GraphDirected15 GraphDirected15.cpp)
# add_executable(GraphDirectedDFS_Cycle15 GraphDirectedDFS_Cycle15.cpp)
# add_executable(GraphDirectedDFS_DFOrdering15 GraphDirectedDFS_DFOrdering15.cpp)
# add_executable(GraphDirectedDFS_TopologicalSort_Concise1 GraphDirectedDFS_TopologicalSort_Concise1.cpp )
# add_executable(GraphDirectedDFS_KosarajuSCC15 GraphDirectedDFS_KosarajuSCC15.cpp)
# add_executable(GraphDirectedDFS_TransitiveClosure15 GraphDirectedDFS_TransitiveClosure15.cpp)
# add_executable(MinPQ15 MinPQ15.cpp)
# add_executable(MinPQ_STL1 MinPQ_STL1.cpp)
# add_executable(IndexMinPQ15 IndexMinPQ15.cpp)
# add_executable(QuickSort10 QuickSort10.cpp)
# add_executable(QuickSelect10 QuickSelect10.cpp)
# add_executable(GraphDirectedWeighted_EdgeWeightedDigraph10 GraphDirectedWeighted_EdgeWeightedDigraph10.cpp)
# add_executable(GraphDirectedWeighted_BellmanFordNegCycleSP10 GraphDirectedWeighted_BellmanFordNegCycleSP10.cpp)
# add_executable(GraphDirectedWeighted_AcyclicSP10 GraphDirectedWeighted_AcyclicSP10.cpp)
# add_executable(GraphDirectedWeighted_AcyclicLP1 GraphDirectedWeighted_AcyclicLP1.cpp )
# add_executable(GraphDirectedWeighted_CPMParallelScheduling10 GraphDirectedWeighted_CPMParallelScheduling10.cpp)
# add_executable(GraphDirectedWeighted_Arbitrage1 GraphDirectedWeighted_Arbitrage1.cpp)
# add_executable(GraphDirectedDFS_TarjanSCC10 GraphDirectedDFS_TarjanSCC10.cpp)
# add_executable(GraphDirectedWeighted_FloydWarshallDenseAllPairsSP10 GraphDirectedWeighted_FloydWarshallDenseAllPairsSP10.cpp)
# add_executable(GraphDirectedDFS_JohnsonFindAllCycles10 GraphDirectedDFS_JohnsonFindAllCycles10.cpp)
# add_executable(GraphDirectedWeighted_DijkstraAllPairsSP1 GraphDirectedWeighted_DijkstraAllPairsSP1.cpp)
# add_executable(GraphDirectedWeighted_BellmanFordNegCycleAllPairsSP1 GraphDirectedWeighted_BellmanFordNegCycleAllPairsSP1.cpp)
# add_executable(GraphDirectedWeighted_JohnsonSparseNegCycleAllPairsSP10 GraphDirectedWeighted_JohnsonSparseNegCycleAllPairsSP10.cpp)
# add_executable(RedBlackBST1 RedBlackBST1.cpp)
# add_executable(SegmentTree15 SegmentTree15.cpp)
# add_executable(GraphDirectedWeighted_LazyDijkstraSP_Concise1 GraphDirectedWeighted_LazyDijkstraSP_Concise1.cpp)
# add_executable(GraphDirectedWeighted_LazyDijkstraKStopSP_Concise1 GraphDirectedWeighted_LazyDijkstraKStopSP_Concise1.cpp)
# add_executable(RadixCountingSort10 RadixCountingSort10.cpp)
# add_executable(RadixLSDStringSort10 RadixLSDStringSort10.cpp)
# add_executable(RadixMSDStringSort10 RadixMSDStringSort10.cpp)
# add_executable(Quick3WaySort10 Quick3WaySort10.cpp)
# add_executable(RadixQuick3WayString10 RadixQuick3WayString10.cpp)
# add_executable(SubStrSearch_Brute10 SubStrSearch_Brute10.cpp)
# add_executable(SubStrSearch_KMP10 SubStrSearch_KMP10.cpp)
# add_executable(SubStrSearch_BoyerMoore15 SubStrSearch_BoyerMoore15.cpp)
# add_executable(PrimalityTest_SchoolMethod10 PrimalityTest_SchoolMethod10.cpp)
# add_executable(PrimalityTest_SchoolMethodOptimized10 PrimalityTest_SchoolMethodOptimized10.cpp)
# add_executable(ModularExponent15 ModularExponent15.cpp)
# add_executable(PrimalityTest_MillerRabin10 PrimalityTest_MillerRabin10.cpp)
# add_executable(SimpleSieve10 SimpleSieve10.cpp)
# add_executable(SegmentedSieve10 SegmentedSieve10.cpp)
# add_executable(StringHash_HornerMethod10 StringHash_HornerMethod10.cpp)
# add_executable(SubStrSearch_RabinKarp10 SubStrSearch_RabinKarp10.cpp)
# add_executable(NextPermutation10 NextPermutation10.cpp)
# add_executable(GCD0 GCD0.cpp)
# add_executable(MajorityVote_BoyerMoore2 MajorityVote_BoyerMoore2.cpp)
# add_executable(CustomComparator_FindUsingLowerBound0 CustomComparator_FindUsingLowerBound0.cpp)
# add_executable(SearchExponential0 SearchExponential0.cpp)
# add_executable(InsertionSort0 InsertionSort0.cpp)
# add_executable(MergeSort0 MergeSort0.cpp)
# add_executable(MergeSort_BottomUp0 MergeSort_BottomUp0.cpp)
# add_executable(HeapSort0 HeapSort0.cpp)
# add_executable(MultiThreading_LockGuard0 MultiThreading_LockGuard0.cpp)
# add_executable(MultiThreading_ConditionVariables0 MultiThreading_ConditionVariables0.cpp)
# add_executable(FenwickBITTree0 FenwickBITTree0.cpp)
# add_executable(GraphDirectedDFS_EulerianCycle1VisitPerEdge0 GraphDirectedDFS_EulerianCycle1VisitPerEdge0.cpp)
# add_executable(GraphDirectedDFS_EulerianPath1VisitPerEdge0 GraphDirectedDFS_EulerianPath1VisitPerEdge0.cpp)

# add_executable(GraphUndirectedDFS_CC15 GraphUndirectedDFS_CC15.cpp)
# add_executable(GraphUndirectedDFS_Cycle15 GraphUndirectedDFS_Cycle15.cpp)
# add_executable(GraphUndirectedDFS_TwoColor15 GraphUndirectedDFS_TwoColor15.cpp)
# add_executable(GraphUndirectedDFS_Bridge15 GraphUndirectedDFS_Bridge15.cpp)
# add_executable(GraphUndirectedDFS_BiconnectedArticulationPoints1 GraphUndirectedDFS_BiconnectedArticulationPoints1.cpp)
# add_executable(GraphUndirectedDFS_HamiltonianCyclePath1VisitPerVertex0 GraphUndirectedDFS_HamiltonianCyclePath1VisitPerVertex0.cpp)
# add_executable(GraphUndirectedDFS_EulerianCycle1VisitPerEdge0 GraphUndirectedDFS_EulerianCycle1VisitPerEdge0.cpp)
# add_executable(GraphUndirectedDFS_EulerianPath1VisitPerEdge0 GraphUndirectedDFS_EulerianPath1VisitPerEdge0.cpp)
# add_executable(GraphUndirectedBFP_SymbolGraph15 GraphUndirectedBFP_SymbolGraph15.cpp)
# add_executable(GraphUndirectedBFS_PatonFindAllFundamentalCycles10 GraphUndirectedBFS_PatonFindAllFundamentalCycles10.cpp)
# add_executable(GraphUndirectedWeighted_EdgeWeightedGraph15 GraphUndirectedWeighted_EdgeWeightedGraph15.cpp)
# add_executable(GraphUndirectedWeighted_LazyPrimMST15 GraphUndirectedWeighted_LazyPrimMST15.cpp)
# add_executable(GraphUndirectedWeighted_PrimMST15 GraphUndirectedWeighted_PrimMST15.cpp)
# add_executable(GraphUndirectedWeighted_KruskalMST15 GraphUndirectedWeighted_KruskalMST15.cpp)
# add_executable(GraphUndirectedWeighted_PrimMSF1 GraphUndirectedWeighted_PrimMSF1.cpp)
# add_executable(GraphUndirectedWeighted_LazyPrimMSF1 GraphUndirectedWeighted_LazyPrimMSF1.cpp)
# add_executable(GraphUndirectedWeighted_KruskalMSF1 GraphUndirectedWeighted_KruskalMSF1.cpp)

# add_executable(DP_Fibonacci10 DP_Fibonacci10.cpp)
# add_executable(DP_MakingChange10 DP_MakingChange10.cpp)
# add_executable(DP_SquareSubMatrix10 DP_SquareSubMatrix10.cpp)
# add_executable(DP_Knapsack10 DP_Knapsack10.cpp)
# add_executable(DP_TargetSum10 DP_TargetSum10.cpp)

# add_executable(LCD LCD0.cpp)

# add_executable(GraphUndirectedDFP15 GraphUndirectedDFP15.cpp)
# add_executable(GraphUndirectedBFP15 GraphUndirectedBFP15.cpp)
# add_executable(GraphDirectedDFS15 GraphDirectedDFS15.cpp)
# add_executable(GraphDirectedDFP15 GraphDirectedDFP15.cpp)
# add_executable(GraphDirectedBFP15 GraphDirectedBFP15.cpp)


# CURRENTLY PRACTICING

# add_executable(BinaryTree_MorrisIterativeRecursiveTraversal10 BinaryTree_MorrisIterativeRecursiveTraversal10.cpp)
# add_executable(LargestSumContiguousArray_Kadane_DivideConquer5 LargestSumContiguousArray_Kadane_DivideConquer5.cpp)
# add_executable(DP_LargestProductContiguousArray_Kadane5 DP_LargestProductContiguousArray_Kadane5.cpp)
# add_executable(MultipleSameSizeArrays_CountSumProduct_AllCombinations_Matrix2 MultipleSameSizeArrays_CountSumProduct_AllCombinations_Matrix2.cpp)
# add_executable(LinkedListSingly5 LinkedListSingly5.cpp)
# add_executable(StdSortCustomFunction0 StdSortCustomFunction0.cpp)

# add_executable(GraphUndirected15 GraphUndirected15.cpp)

# add_executable(UserDefinedTypeHash1 UserDefinedTypeHash1.cpp)
# add_executable(GraphUndirectedDFS5 GraphUndirectedDFS5.cpp)

# add_executable(UF_WeightedQuickUnionPathCompression15 UF_WeightedQuickUnionPathCompression15.cpp)
# add_executable(UF_WeightedQuickUnionPathCompression0 UF_WeightedQuickUnionPathCompression0.cpp)
#
# add_executable(MonotonicStack0 MonotonicStack0.cpp)
# add_executable(MonotonicStack1 MonotonicStack1.cpp)
#
# add_executable(MonotonicQueue0 MonotonicQueue0.cpp)

# add_executable(TrieSET_Concise0 TrieSET_Concise0.cpp)
# add_executable(TrieSET_Concise1 TrieSET_Concise1.cpp)
# add_executable(TrieSET_Concise2 TrieSET_Concise2.cpp)
# add_executable(TrieSET_Concise3 TrieSET_Concise3.cpp)
# add_executable(TrieSET_Concise4 TrieSET_Concise4.cpp)
# add_executable(TrieSET_Concise5 TrieSET_Concise5.cpp)

# add_executable(TrieST15 TrieST15.cpp)
# add_executable(TrieBitwiseSET_Concise0 TrieBitwiseSET_Concise0.cpp)
# add_executable(TST10 TST10.cpp)
# add_executable(TrieBitwiseST0 TrieBitwiseST0.cpp)

# add_executable(SearchBinary0 SearchBinary0.cpp)
# add_executable(SearchBinary_LeftMost0 SearchBinary_LeftMost0.cpp)
# add_executable(SearchBinary_LeftMost_LowerBound0 SearchBinary_LeftMost_LowerBound0.cpp)
# add_executable(SearchBinary_RightMost0 SearchBinary_RightMost0.cpp)
# add_executable(SearchBinary_RightMost_UpperBound0 SearchBinary_RightMost_UpperBound0.cpp)


# LEETCODE EXERCISES


# #
# # DEPRECATED
# #
# # add_executable(TrieSET0 deprecated/TrieSET0.cpp)
# # add_executable(TrieBitwiseSET0 deprecated/TrieBitwiseSET0.cpp)
# # add_executable(GraphDirectedWeighted_LazyDijkstraSP1 deprecated/GraphDirectedWeighted_LazyDijkstraSP1.cpp)
# # add_executable(GraphDirectedDFS_TopologicalSort15 deprecated/GraphDirectedDFS_TopologicalSort15.cpp )
# # add_executable(GraphDirectedWeighted_DijkstraSP10 deprecated/GraphDirectedWeighted_DijkstraSP10.cpp)
# # add_executable(GraphDirectedDFS_HamiltonianCyclePath1VisitPerVertex0 GraphDirectedDFS_HamiltonianCyclePath1VisitPerVertex0.cpp)
# #
