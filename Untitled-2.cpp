
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    const int k=image[sr][sc];
        
            image[sr][sc]=color;
        cout<<" sr sc "<<sr<<sc<<endl;
        if ((sr-1)>=0 && image[sr-1][sc]==k){
            cout<<"1st\n";
            floodFill(image,sr-1,sc,color);
        }
        if ((sc-1)>=0 && image[sr][sc-1]==k){
            cout<<"2st\n";

            floodFill(image,sr,sc-1,color);}
            
        if ((sr+1)<image.size() && image[sr+1][sc]==k){
            cout<<"3rd\n";

           floodFill(image,sr+1,sc,color);
        }

        if ((sc+1)<image[0].size() && image[sr][sc+1]==k){
            cout<<"4st\n";

            floodFill(image,sr,sc+1,color);
        }
        cout<<endl;

    return image;
}

int main(){
   vector<vector<int>> v ={{0, 0, 0}, {0,0,0 }}; 
   	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
    cout<<endl;
    floodFill(v,1,0,2);
    cout<<"hi"<<endl;
    for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}


}
