int REcomapre(char* left, int leftindex, char*right, int rightindex)
{
    //end condition
    if(leftindex == strlen(left) && rightindex == strlen(right)) {
        return true;
    }

    //boundary case
    if(rightindex == strlen(right)-1) {
        if(left[leftindex] == right[rightindex] || right[rightindex] == '.') {
            if(leftindex == strlen(left)-1){
                return true;
            }
            else if(leftindex < strlen(left)-1){
                //left is not finished
                return false;
            }
        } 
        else {
            return false;
        }   
    }
    //easy case
    if(right[rightindex+1] != '*') {
        if(left[leftindex] == right[rightindex]) {
            return REcomapre(left, leftindex+1, right, rightindex+1);
        } 
        else if(right[rightindex] == '.') {
            return REcomapre(left, leftindex+1, right, rightindex+1);
        }
        else {
            return false;
        }
    }
    else {
        if(rightindex+2 != strlen(right)) {
            //skip
            for(int i = leftindex; i < strlen(left); i++) {
                if(right[rightindex] == '.') {
                    //skip all
                    if(REcomapre(left, i, right, rightindex+2)) {
                        return true;
                    }
                }
                else if(left[i] == right[rightindex]) {
                    //skip until equal happen
                    if(REcomapre(left, i, right, rightindex+2)) {
                        return true;
                    }
                }
            }
            //skip to next char
            //case : "ab"  "c*a*b" => "ab" "a*b"
            return REcomapre(left, leftindex, right, rightindex+2);
        }
        else {
        //special case end of right is '*'
        //so from leftindex to end should be all equal to 'right[rightindex]'
            int flag = 0;
            for(int i = leftindex; i < strlen(left); i++) {
                if(right[rightindex] != '.' && left[i] != right[rightindex]) {
                   flag = 1;
                }
                if(flag) {
                    return false;
                }
            }
            return true;
        }
        
    }
    
}

bool isMatch(char* s, char* p) {
    return REcomapre(s,0,p,0);
}