//Problem:008--旋转数组的最小数字
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个
//旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
//NOTE:给出的所有元素都大于0，若数组大小为0，请返回0。
//Main strategy:
//来自https://blog.csdn.net/gatieme/article/details/51115386
//分治-二分查找
//首先我们用两个指针，分别指向数组的第一个元素和最后一个元素。按照题目旋转的规则，第一个元素应该是
//大于或者等于最后一个元素的（这其实不完全对，还有特例。后面再讨论特例）。
//接着我们得到处在数组中间的元素
//1.如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素。此时数组中最小
//的元素应该位于该中间 元素的后面。我们可以把第一指针指向该中间元素，这样可以缩小寻找的范围。
//2.同样，如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指向的元素。此时该数组
//中最小的元素应该位于该中间元素的前面。我们可以把第二个指针指向该中间元素，这样同样可以缩小寻找的
//范围。我们接着再用更新之后的 两个指针，去得到和比较新的中间元素，循环下去。
//3.特殊情况:[1, 0, 1, 1, 1],此时rotateArray[low],rotateArray[mid],rotateArray[high]
//三者相等,无法确定中间元素是属于前面还是后面的递增子数组,只能顺序查找。


#include <iostream>
#include <vector>
using namespace std;

//  调试开关
//#define __tmain main

#ifdef __tmain
    #define debug cout
#else
    #define debug 0 && cout
#endif // __tmain


class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size( ) == 0)
        {
            debug <<"非法输入" <<endl;
            return 0;
        }

        //  如果把排序数组前面0个元素搬到后面，也就是说其实没有旋转，
        //  那么第0个元素就是最小的元素
        //  因此我们将mid初始化为0
        int mid = 0;
        int low = 0, high = rotateArray.size( ) - 1;
        if(rotateArray[low] < rotateArray[high])
        {
            debug <<"数组未被旋转" <<endl;
        }
        while(rotateArray[low] >= rotateArray[high])
        {
            //  如果前一个元素与后一个元素差一位
            //  说明找到了最大最小的元素
            if(high - low == 1)
            {
                mid = high;
                debug <<"min = " <<low <<", high = " << high << endl;
                break;
            }

            mid = (low + high) / 2;
            debug << rotateArray[low] << ", " << rotateArray[mid] << ", " << rotateArray[high] << endl;

            // rotateArray[low] rotateArray[mid] rotateArray[high]三者相等
            // 无法确定中间元素是属于前面还是后面的递增子数组
            // 只能顺序查找
            if(rotateArray[low] == rotateArray[mid] && rotateArray[mid] == rotateArray[high])
            {
                debug << "low == mid == high, so we should order it" << endl;
                debug << low << mid << high << endl;
                return MinOrder(rotateArray, low, high);
            }
            // 如果该中间元素位于前面的递增子数组，那么它应该大于或者等于第一个指针指向的元素
            if(rotateArray[mid] >= rotateArray[low])
            {
                low = mid;          //  此时最小的元素位于中间元素的后面
            }
            // 如果中间元素位于后面的递增子数组，那么它应该小于或者等于第二个指针指 向的元素
            else if(rotateArray[mid] <= rotateArray[high])
            {
                high = mid;         //  此时最小的元素位于中间元素的前面
            }
        }

        return rotateArray[mid];
    }

private:
    // 顺序寻找最小值
    int MinOrder(vector<int> &num, int low, int high)
    {
        int result = num[low];
        for(int i = low + 1; i < high; i++)
        {
            if(num[i] < result)
            {
                result = num[i];
            }//if
        }//for
        return result;
    }

};

int main()
{
    int a[] = {1, 0, 1, 1, 1};
    vector<int> vec(a, a + 5);
    vector<int> mn(3, 8);
    vector<int> c(mn);
    for(int i = 0; i < c.size(); ++i)
    {
        cout << c[i] << endl;
    }
    Solution solu;
    cout << solu.minNumberInRotateArray(vec) << endl;

    return 0;
}


