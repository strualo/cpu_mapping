建 图: roslaunch ndt_mapping ndt_mapping.launch

调试记录： 1.用过滤地面后的雷达数据建图会导致z轴上飘

2.min_add_scan_shift 设置过小会导致建图失败

3.voxel_leaf_size: 0.2 # 对输入的 一帧点云做第一次降采样

4.global_voxel_leafsize: 0.1 #将一帧点云添加到 full_map之前降采样

5.passthrough_ground_height
