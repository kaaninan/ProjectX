FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/touchosc_msgs/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/touchosc_msgs/msg/__init__.py"
  "../src/touchosc_msgs/msg/_Tabpage.py"
  "../src/touchosc_msgs/msg/_XYPad.py"
  "../src/touchosc_msgs/msg/_Label.py"
  "../src/touchosc_msgs/msg/_TouchOSC_Common.py"
  "../src/touchosc_msgs/msg/_MultiButton.py"
  "../src/touchosc_msgs/msg/_MultiXYPad.py"
  "../src/touchosc_msgs/msg/_CommonProperties.py"
  "../src/touchosc_msgs/msg/_ScalableControl.py"
  "../src/touchosc_msgs/msg/_MultiFader.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
