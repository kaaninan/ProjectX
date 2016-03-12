FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/touchosc_msgs/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/touchosc_msgs/Tabpage.h"
  "../msg_gen/cpp/include/touchosc_msgs/XYPad.h"
  "../msg_gen/cpp/include/touchosc_msgs/Label.h"
  "../msg_gen/cpp/include/touchosc_msgs/TouchOSC_Common.h"
  "../msg_gen/cpp/include/touchosc_msgs/MultiButton.h"
  "../msg_gen/cpp/include/touchosc_msgs/MultiXYPad.h"
  "../msg_gen/cpp/include/touchosc_msgs/CommonProperties.h"
  "../msg_gen/cpp/include/touchosc_msgs/ScalableControl.h"
  "../msg_gen/cpp/include/touchosc_msgs/MultiFader.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
