#include <iostream>
#include <cstdlib>

using namespace std;





int main() {
    string filename = "/pointcloud_pcd/1668162552.627556324.pcd";
    string command = "pcl_viewer " + filename;
    system(command.c_str());
    return 0;
}
