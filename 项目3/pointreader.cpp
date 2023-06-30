#include <iostream>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/pcd_io.h>
#include <boost/filesystem.hpp>

// 比较函数，用于对文件名进行排序
bool compare(const std::string& a, const std::string& b)
{
  // 提取文件名中的时间戳部分并进行比较
  double time_a = std::stod(a.substr(0, a.find('.')));
  double time_b = std::stod(b.substr(0, b.find('.')));
  return time_a < time_b;
}

int main(int argc, char** argv)
{
  // 设置读取文件的路径
  std::string path = "/pointcloud_pcd";

  // 获取目录下的所有.pcd文件并排序
  boost::filesystem::directory_iterator end_itr;
  std::vector<std::string> files;
  for (boost::filesystem::directory_iterator itr(path); itr != end_itr; ++itr)
  {
    if (boost::filesystem::is_regular_file(itr->path()) && itr->path().extension() == ".pcd")
    {
      files.push_back(itr->path().string());
    }
  }
  std::sort(files.begin(), files.end(), compare);

  // 创建PCD Viewer对象并展示点云
  pcl::visualization::CloudViewer viewer("PCD Viewer");
  for (const std::string& file : files)
  {
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(file, *cloud) == -1)
    {
      std::cerr << "Failed to read PCD file: " << file << std::endl;
      break;
    }
    viewer.showCloud(cloud);
    usleep(100000); // 暂停100毫秒
  }

  return 0;
}