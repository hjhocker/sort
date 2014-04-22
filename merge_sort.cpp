#include "sort_vector.cpp"

void merge_sort ( float nums[], int *num) {
	std::vector<int> list;

	for (int i=1;i<*num;i++) 
		list.push_back(nums[i]);
	//vector objects:
	//begin, return iterator to beginging
	//end, return itererator to end
	//size ,gives number of elements
	//resize, change size of the vector
	//empty, test if the vector is empty
	//at, acces element at a position
	//insert, insert element at a position
	//erase, erase an element at a position
	//swap, swap two elements
	//clear, delete contents of a vector

	int length = list.size();
	bool isEven = length % 2 == 0;

	std::vector<int> vector;
	std::vector< std::vector<int> > matrix;

	//break float array into a multilevel matrix
	if (isEven) {
		for (int i=0;i<list.size();i=i+2) {
			vector.push_back(list.at(i));
			vector.push_back(list.at(i+1));
			matrix.push_back(vector);
			vector.clear();
		}
	} else {
			vector.push_back(list.at(0));
			vector.push_back(list.at(1));
			vector.push_back(list.at(2));
			matrix.push_back(vector);
			vector.clear();
		for (int i=3;i<list.size();i=i+2) {
			vector.push_back(list.at(i));
			vector.push_back(list.at(i+1));
			matrix.push_back(vector);
			vector.clear();
		}

	}
	bool display = 0;
	if (display)
	for (int i=0;i<matrix.size();i++) 
	for (int j=0;j<matrix.at(i).size();j++) 
			if(display)std::cout << "Row i " << i << " Column j " << j << " value " << matrix.at(i).at(j) << std::endl;



	int a=0;
	int b=a+1;
	std::vector<int> vec1, vec2;

	//merge the rows in the matrix and sort them as we go
	while (matrix.size() > 1) {
		if(display)std::cout << "Matrix size " << matrix.size() << std::endl;
		if(display)std::cout << "YES a " << a << " b " << b << std::endl;
		vec1 = matrix.at(a);
		vec2 = matrix.at(b);
		vec1.insert(vec1.end(), vec2.begin(), vec2.end());
		sort_vector2(&vec1);
		matrix.at(a) = vec1;
		matrix.erase(matrix.begin()+b);
		a = a + 2;
		b = a + 1;
		if(display)std::cout << "YES2 a " << a << " b " << b << std::endl;
		if (b >= matrix.size()) {
			if(display)std::cout << "Reset: b is " << b << ", matrix size " << matrix.size() << std::endl;
			a = 0;
			b = a + 1;
		}
	}

	int count = 1;
	for (int i=0;i<matrix.size();i++) 
		for (int j=0;j<matrix.at(i).size();j++) {
			if(display)std::cout << "Row i " << i << " Column j " << j << " value " << matrix.at(i).at(j) << std::endl;
			nums[count] = matrix.at(i).at(j);
			count++;
		}

	return;
}
