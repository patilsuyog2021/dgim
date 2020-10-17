#include<iostream>
#include<string>
#include<unordered_map>
#include<utility>
#include<deque>
using namespace std;

unordered_map <int,deque<pair<int,int>>>buckets;
string bitstream{""};
string input_bitstream{""};

void arrange_buckets(){
	for(int i=0;i < static_cast<int>(buckets.size());++i){
		if(buckets[i].size() > 2){
			int start = buckets[i][0].first;
			int end = buckets[i][1].second;
			buckets[i].pop_front();
			buckets[i].pop_front();
			buckets[i+1].push_back(make_pair(start,end));//adding to next buckets
		}	
	}
	
}
int get_ones(){
	
	cout<<"Enter the window size to calculate: ";
	int window_size{0};
	cin>>window_size;
	
	for(int len = 0;len < static_cast<int>(input_bitstream.length()); ++len){
		if(input_bitstream[len] == '0'){
			bitstream.push_back(input_bitstream[len]);
		}
		else if (input_bitstream[len] == '1'){
			bitstream.push_back(input_bitstream[len]);
			buckets[0].push_back(make_pair(bitstream.length()- 1,bitstream.length()- 1) );//inserting at end.

			arrange_buckets();
		}
	}
	
	
	int ones_count{0};
	for(int i= 0,j= 1;
		i < static_cast<int>(buckets.size()) && buckets[i][j].first > (static_cast<int>(bitstream.size()) - window_size);
		--j){
		if(i == static_cast<int>(buckets.size())-1){
			if(buckets[i].size() == 1 || j == 0){
				ones_count += (i+1)/2;
				break;
			}
		}
		
		ones_count += (i+1);
 		
		if(j == 0){
			j = 2;
			++i;
		}
	}
		
	return ones_count;
}

int main(){
	int choice{0};
	
	while(true){
		cout<<"\n 1.Add bit stream: ";
		cout<<"\n 2.Query the no. of 1's";
		cout<<"\n 3.Exit";
		cout<<"\nEnter the choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the bits:"
				cin>>input_bitstream;
				break;
			case 2:
				cout<<"The number of 1s are: "<<get_ones()<<"\n";
				break;
			case 3:
				return 0;
		}
	}
	return 0;
}
// 1010110001011101100101101 1
