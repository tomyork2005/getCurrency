# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-src"
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-build"
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix"
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/tmp"
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src"
  "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/swuxy/CLionProjects/verylasssy/cmake-build-debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
