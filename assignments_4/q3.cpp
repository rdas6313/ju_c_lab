#include<iostream>
using namespace std;

class Number_List{
	int *nums;
	int length;
	public:
		void create_array(){
			int n;
			cout << "No of elements in array: ";
			cin >> n;
			length = n;
			nums = new int[n];
			cout << "Elements of array: ";
			for(int i=0;i<n;i++)
				cin >> nums[i];
		}

		void sort(){
			int n = length;
			for(int i=0;i<n-1;i++){
				for(int j=i+1;j<n;j++){
					if(nums[i] > nums[j]){
						int tmp = nums[i];
						nums[i] = nums[j];
						nums[j] = tmp;
					}
				}
			}
			cout << "sorted array: ";
			for(int i=0;i<n;i++)
				cout << nums[i] << " ";
			cout << endl;
		}
		void maximum(){
			int n = length;
			int max = nums[0];
			for(int i=0;i<n;i++){
				if(max < nums[i])
					max = nums[i];
			}
			cout << "Maximum: " << max << endl;
		}
		void minimum(){
			int n = length;
			int min = nums[0];
			for(int i=0;i<n;i++){
				if(min > nums[i])
					min = nums[i];
			}
			cout << "Minimum: " << min << endl;

		}
};

int main(){
	Number_List list;
	list.create_array();
	list.sort();
	list.maximum();
	list.minimum();
	return 0;
}