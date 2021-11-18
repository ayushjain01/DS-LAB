#include <stdio.h>

int nsteps = 0;

void move(int n, char source, char destination, char temp){
    if (n == 1){
        nsteps++;
        printf("\nStep %d : Move disc %d from %c to %c", nsteps, n, source, destination);
        return;
    }
    
    move(n-1,source,temp,destination);
    nsteps++;
    printf("\nStep %d : Move disc %d from %c to %c", nsteps, n, source,destination);
    move(n-1,temp,destination,source);
}

void main(){
    int n;
    char source = 'A', destination = 'C', temp = 'B';
    printf("\nEnter number of discs : ");
    scanf("%d",&n);
    printf("\nSource : %c\nDestination : %c\nTemp : %c", source, destination,temp);
    move(n,source,destination,temp);
}
