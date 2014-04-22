
void sort_vector (std::vector<int> *data) {
	int length = data->size();
	int temp;

	if (length==2) {
		if (data->at(0) > data->at(1)) {
			temp = data->at(0);
			data->at(0) = data->at(1);
			data->at(1) = temp;
			return;
		}
	}	


	if (length==3) {
		if (data->at(0) > data->at(1)) {
			temp = data->at(0);
			data->at(0) = data->at(1);
			data->at(1) = temp;
			return;
		}
		if (data->at(1) > data->at(2)) {
			temp = data->at(1);
			data->at(1) = data->at(2);
			data->at(2) = temp;
			return;
		}
		if (data->at(0) > data->at(1)) {
			temp = data->at(0);
			data->at(0) = data->at(1);
			data->at(1) = temp;
			return;
		}
	}

}


void sort_vector2 (std::vector<int> *data) {
	int length = data->size();
	int temp;
	for (int i=0;i<length;i++) {
		for (int j=i+1;j<length;j++) {
			if (data->at(i) > data->at(j)) {
			//temp = data->at(i);
			//data->at(i) = data->at(j);
			//data->at(j) = temp;
			std::swap(data->at(i), data->at(j));
			}
		}
	}

	return;
}

