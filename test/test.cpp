#include "sophus/geometry.hpp"
//#include "Eigen\Dense"
#include "Eigen/Geometry"
#include <math.h>

using namespace std;
int main() {
	// 绕z轴旋转90度
	Eigen::AngleAxisd rotation_vector(M_PI / 2, Eigen::Vector3d(0, 0, 1));
	Eigen::Matrix3d rotation_matrix = rotation_vector.toRotationMatrix();
	Eigen::Quaterniond rotation_quaterniond(rotation_matrix);

	/* ------------------SO3/so3---------------*/
	// SO3构造
	Sophus::SO3d SO3_R(rotation_matrix); // 从矩阵直接构造
	Sophus::SO3d SO3_Q(rotation_quaterniond); // 从四元数构造
	// 输出时，需要.matrix()输出矩阵
	cout << "this from matrix : \n" << SO3_R.matrix() << endl;
	cout << "this from quater : \n" << SO3_Q.matrix() << endl;

	// SO3.log()就可以将SO3上的元素对数表示到so3中，其中so3的定义依然是Vector3d,其实就是Eigen中的类。
	Eigen::Vector3d so3 = SO3_Q.log();
	cout << "so3 = \n" << so3.transpose() << endl;

	// 使用SO3d::hat()可以实现so3->SO3的转换。
	cout << "so3 hat= \n" << Sophus::SO3d::hat(so3) << endl;

	// 使用so3d::vee可以实现SO3->so3的转换：
	cout << "SO3 vee=\n" << Sophus::SO3d::vee(Sophus::SO3d::hat(so3)).transpose() << endl;
	
	// Sophus中提供exp用来进行计算导数
	Eigen::Vector3d update_so3(1e-4, 0, 0); //增加扰动
	Sophus::SO3d SO3_updated = Sophus::SO3d::exp(update_so3) * SO3_R;
	cout << "SO3 update =\n" << SO3_updated.matrix() << endl;

	/* ------------------se3/SE3---------------*/
	Eigen::Vector3d t(1, 0, 0);
	Sophus::SE3d SE3_Rt(rotation_matrix, t);
	Sophus::SE3d SE3_qt(rotation_quaterniond, t);

	cout << "this from matrix : \n" << SE3_Rt.matrix() << endl;
	cout << "this from quater : \n" << SE3_qt.matrix() << endl;

	// SE3->se3: 因为se3为6维的向量，而Eigen中没有6为vecor6d,所以自己定义一个
	typedef Eigen::Matrix<double, 6, 1>  Vector6d;
	Vector6d se3 = SE3_Rt.log();
	cout << "se3= \n" << se3.transpose() << endl;     //平移在前而旋转在后

	//将se3转换到SE3中: 同样使用exp和vee
	 
	cout << "se3 hat= \n" << Sophus::SE3d::hat(se3) << endl;

	// 将SE3转换到se3中
	cout << "SE3 vee=\n" << Sophus::SE3d::vee(Sophus::SE3d::hat(se3)).transpose() << endl;

	//同样加入扰动
	Vector6d update_se3;
	update_se3.setZero();
	update_se3(1, 0) = 1e-4;
	cout << "update_se3 is \n" << update_se3.transpose() << endl;
	Sophus::SE3d SE3_updated = Sophus::SE3d::exp(update_se3) * SE3_Rt;
	cout << " SE3 update is \n" << SE3_updated.matrix() << endl;
	system("pause");
	return 0;
}