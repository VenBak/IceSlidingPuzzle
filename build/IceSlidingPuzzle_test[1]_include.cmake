if(EXISTS "/Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build/IceSlidingPuzzle_test[1]_tests.cmake")
  include("/Users/andrebrahin/Computing_Science/IceSlidingPuzzle/build/IceSlidingPuzzle_test[1]_tests.cmake")
else()
  add_test(IceSlidingPuzzle_test_NOT_BUILT IceSlidingPuzzle_test_NOT_BUILT)
endif()