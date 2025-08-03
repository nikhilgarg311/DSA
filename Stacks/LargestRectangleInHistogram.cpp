class Solution {
private:
 vector<int> prevSmallerElementIndex(vector<int> heights){
    stack<int> s;
    vector<int> arr(heights.size());
    for(int i=0;i<heights.size();i++){
        if(!s.empty() && s.top()!=-1 && heights[s.top()]<heights[i]){
            arr[i]=s.top();
        }
        else{
            if(s.empty()){
                arr[i]=(-1);
            }
            else{
                while(!s.empty()&& s.top()!=-1 && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(s.empty()){
                    arr[i]=(-1);
                }
                else{
                    arr[i]=s.top();
                }
            } 
        }
        s.push(i);
    }
    return arr;

 }
 vector<int> nextSmallerElementIndex(vector<int> heights){
    stack<int> s;
    vector<int> arr(heights.size());
    for(int i=heights.size()-1;i>=0;i--){
        if(!s.empty() && s.top()!=-1 && heights[s.top()]<heights[i]){
            arr[i]=(s.top());
        }
        else{
            if(s.empty()){
                arr[i]=(-1);
            }
            else{
                while(!s.empty()&& s.top()!=-1 && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                if(s.empty()){  
                    arr[i]=(-1);
                }
                else{
                    arr[i]=s.top();
                }
            } 
        }
        s.push(i);
    }
    return arr;
 }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev;
        vector<int>next;

        prev= prevSmallerElementIndex(heights);
        next= nextSmallerElementIndex(heights);
        int area=0;
        for(int i=0;i<heights.size();i++){

            if(next[i]==-1){
                next[i]=heights.size();
            }
            int newArea=heights[i]* (next[i]-prev[i]-1);
            area=max(area,newArea);
        }
        return area;
        
    }
};