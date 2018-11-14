// sort

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) { 
    return (a.second < b.second); 
} 

sort(data.begin(), data.end(), sortbysec);

// Qsort
void my_sort(int left, int right){
	int key = a[(left+right)/2];
	if(left <= right){
		int i = left;
		int j = right;
		while(i<=j){
			while(a[i] > key) i++;
			while(a[j] < key) j--;
			if(i <= j){
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		if(left <= i){
			my_sort(left,j);
		}
		if(right >= j){
			my_sort(i, right);
		}
	}
}

// binary search
while (high - low > eps){
	double mid = (low + high) / 2.0;
			
	if (F(mid) > 0) {
		low = mid;
	} else {
		high = mid; 
	}
}		
printf("%0.6f \n", low);

while (left <= right) {
	
	int mid = (right + left) / 2;
	
	if (isValid(mid)) {
		result = mid;
		left = mid + 1;
	} else {
		right = mid - 1;
	}
}

// read write file
freopen("holeyqueens.inp", "r", stdin);
freopen("holeyqueens.inp", "w", stdin);
