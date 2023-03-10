#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char *Curpos;
char *alphabet;
int *truthlist;

int findtruthvalue(char letter){
    int i,index;
    for(i=0;i<27;i++){
        if(letter==alphabet[i])
            index=i;
    }
    return truthlist[index];
}

void skip(){
    while(*Curpos==' ')
        Curpos++;
}

int read_and_eval_from_curpos(){
    int left, right;
    char oper;
    skip();
    if(*Curpos=='('){
        
        Curpos++;
        skip();
        left=read_and_eval_from_curpos();
        oper=*Curpos++;
        skip();
        right=read_and_eval_from_curpos();
        Curpos++;
        skip();
        switch (oper){
            case '&': return left&&right; break;
            case '|': return left||right; break;
            case '>': return !(left)||right; break;
            case '=': return left==right; break;
        }}
        
    else{
        if(*Curpos=='-'){
            Curpos++;
            skip();
            left=!(read_and_eval_from_curpos());
            return left;
        }
        left=findtruthvalue(*Curpos);
        Curpos++;
        skip();
        return left;
    }
    return 31;
    }

char frominttochar(int a){
    if(a!=0)
        return 'T';
    else return 'F';
}






int isin(char letter, char*alphabet,int index){
    int i;
    for(i=0;i<index;i++){
        if(letter==alphabet[i])
            return 1;
    }
    return 0;
}


int main() {
    char *dummy;
    int a=0, i=0,index,j=0,key;
    Curpos=calloc(1,sizeof(char));
    alphabet=calloc(27,sizeof(char));
    
    
    while((Curpos[a]=getchar())!=EOF){
        Curpos = realloc(Curpos,(++a+1)*sizeof(char));
    }
 
    for(i=0,index=0;i<a;i++){
        if(97<=Curpos[i] && Curpos[i]<=122)
            if(!(isin(Curpos[i],alphabet,index))){
                alphabet[index]=Curpos[i];
                index++;}
        }
        
    /*sort*/
    for (i = 1; i < index; i++) {
        key = alphabet[i];
        j = i - 1;
        while (j >= 0 && alphabet[j] > key) {
            alphabet[j + 1] = alphabet[j];
            j = j - 1;
        }
        alphabet[j + 1] = key;
    }
    
    for(i=0;i<index;i++)
        printf("%c ",alphabet[i]);
    printf("R\n");
    
    truthlist=calloc(index,sizeof(int));
    dummy=Curpos;
    for(i=0;i<pow(2,index);i++){
        
        for(j=0;j<index;j++){
            if(i%(int)pow(2,index-j)<(pow(2,index-j)/2))
                truthlist[j]=1;
            else
                truthlist[j]=0;
            printf("%c ",frominttochar(truthlist[j]));
            }
            printf("%c\n",frominttochar(read_and_eval_from_curpos()));
            Curpos=dummy;
        
        
    }

    
    
    return 0;
}