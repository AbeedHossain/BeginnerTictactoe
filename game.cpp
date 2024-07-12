#include <bits/stdc++.h>
using namespace std;

class tictactoe{
    private:
    vector<char> positions;
    int input_count{1};
    char turn;
    bool taken{false};
    bool is_finished{false};
    public:

    tictactoe():positions(9,'N'){
        logic_check();
    }
    void post_renderer(){
        int j=0;
        cout<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            if(positions[i*3+j]=='N')cout<<"|"<<" "<<"|";
            else cout<<"|"<<positions[i*3+j]<<"|";
            }
            cout<<endl;
            }
            cout<<endl;
        }


    void pre_renderer(){
        int j=0;
        cout<<endl;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            cout<<"|"<<i*3+j<<"|";
            }
            cout<<endl;
            }
            cout<<endl;
    }
    
    void store(vector<int> location,char turn){
        int location_finder=0;
        location_finder+=location[0];
        location_finder+=location[1]*3;
        if(positions[location_finder]!='N'){
            cerr<<"Already Taken"<<endl;
            taken=true;
        }
         else{
            taken=false;
            if(turn=='X') positions[location_finder]='X';
            else positions[location_finder]='O';
         }
    }

    bool checker(vector<int> ijk){
            if(positions[ijk[0]]==positions[ijk[1]] && positions[ijk[0]]==positions[ijk[2]] && positions[ijk[0]]!='N' && positions[ijk[1]]!='N' && positions[ijk[2]]!='N'){
            cout<<"Winner is "<<positions[ijk[0]]<<endl;
            return true;
            }
            return false;
            
        }

   bool horizontal_checker(){
        
        int i{0},j{1},k{2};
        while(k<9){
            vector<int> ijk;
            ijk.push_back(i);ijk.push_back(j);ijk.push_back(k);
            if(checker(ijk)) return 1;
            i+=3;j+=3;k+=3;
        }
        return false;
    }
    
    bool vertical_checker(){
        
        int i{0},j{3},k{6};
        while(k<9){
            vector<int> ijk;
            ijk.push_back(i);ijk.push_back(j);ijk.push_back(k);
            if(checker(ijk)) return 1;
            i=+3;j+=3;k+=3;
        }
        return false;
    }
    bool diagonal_checker(){
        
        int i{0},j{4},k{8},c{0};
        while(c<2){
            vector<int> ijk;
            ijk.push_back(i);ijk.push_back(j);ijk.push_back(k);
            if(checker(ijk)) return 1;
            i=2,j=4,k=6;c++;
        }
        return false;
    }
    vector<int> location_converter(int a){
        return {a%3,a/3};
    }

    
        
    


    void logic_check(){
       
        
    while(input_count<10){
       
        if(input_count%2==1){
            turn='X';
            pre_renderer();
            
            cout<<"Player 1(X) GO: "<<endl;
            
        }
        else{
            turn='O';
            pre_renderer();
            
            cout<<"Player 1(O) GO: "<<endl;
            
        }
        
        int temp;
        cin>>temp;
           
  
        
        vector<int> location=location_converter(temp);
        store(location,turn);
        post_renderer();
        if(diagonal_checker() || vertical_checker() || horizontal_checker()){
            break;
        }
        else if(input_count==9){
            cout<<"draw!"<<endl;
            break;
        }
        if(taken) input_count=input_count;
        else{input_count++;}
    }
    
    }

};


int main(){
    tictactoe mygame;
    
}