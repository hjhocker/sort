
void random_sequence(float nums[], int *num) {
	int temp;// = (rand() % k) + 1;
	std::vector<int> list;
	bool isPresent=0;
	temp = rand() % (*num-1) + 1;
	list.push_back(temp);
	//std::cout << "Scrable size " << list.size() << std::endl;
	while ( list.size() < (*num-1) ) {
	//std::cout << "Size check " << list.size() << " Goal " << *num << std::endl;
	isPresent = 0;
	temp = rand() % (*num-1) + 1;
		for (int i=0;i<list.size();i++) {
			if (list[i] == temp)
				isPresent = 1;
		}
	if ( ! isPresent ) list.push_back(temp);
	}

	if (0) for (int i=0;i<list.size();i++)
		std::cout << "Scramble " << i << " " << list[i] << std::endl;

	//std::cout << "Scrable size " << list.size() << std::endl;
	bool isEven = list.size() % 2 == 0;

	if ( isEven ) {
	int start = 0;
	while ( start < list.size() ) {
		//std::cout << "even" << std::endl;
		int a = list[start];
		int b = list[start+1];
		//std::cout << "a " << a << " b " << b << std::endl;
		//std::cout << "Swapping " << nums[a] << " with " << nums[b] << " at a & b " << a << " " << b << std::endl;
		std::swap( nums[a], nums[b] );
		start = start + 2;
		}
	}
	else {
		//std::cout << "Odd" << std::endl;
		int start = 0;
		while (start < list.size()-1) {
			int a = list[start];
			int b = list[start+1];
			//std::cout << "a " << a << " b " << b << std::endl;
			//std::cout << "Swapping " << nums[a] << " with " << nums[b] << " at a & b " << a << " " << b << std::endl;
			std::swap( nums[a], nums[b] );
			start = start + 2;
		}
	}

	return;
}