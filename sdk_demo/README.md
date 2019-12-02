lasSegmentLib


Clone:
git clone https://github.com/HesaiTechnology/HaoboImageSDK.git


Build:
cd <project>
mkdir build ; cd build;
cmake .. ; make


Add to your project:
In CmakeList.txt:
add_subdirectory(<path_to>lasSegmentLib)

include_directories(
	<path_to>lasSegmentLib/include
)

target_link_libraries(<Your project>
  lasSegmentLib
)

In codes:
#include lasSegmentLib/include/lasSegment.h"
