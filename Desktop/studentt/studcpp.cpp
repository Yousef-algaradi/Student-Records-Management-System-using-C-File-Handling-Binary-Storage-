#include <stdio.h>
#include <string.h>

struct student{
	char name[100] ;
	int AcadimicNamber;
	int degree[6];
};

void minu ();	//========== «·ﬁ«∆„Â ··«Œ Ì«—«  
void enterInfor();	//===== «œŒ«· «·„⁄·Ê„« 
void search();	//========= «·»ÕÀ ⁄‰ 
void show();	//=========== ⁄—÷ «·»Ì«‰« 


int main()
{
	int o;
		//=======  —ÕÌ»
	printf("welcome to program of student's information \n\n");



	do{
		minu();
		printf("CHOISE : ");
		scanf("%d",&o);
		
		//======== ·«Œ Ì«— ⁄„·ÌÂ 
		switch(o){
			case 1:	enterInfor(); break;
			case 2: show(); break;
			case 3: search(); break;
			case 4:
				printf("The program is ended ^_^ \n");
				break;
		}
	}while(o!=4);

	return 0;
}
	
	//====== œ«·Â „Õ ÊÏ 
void minu (){
	printf("=======ENTER YOUR CHOISE=========\n1- To add infor\n\n2- Show the infor of students\n\n3- To search about infor of student\n\n4- EXIT\n\n");
}
	//========== œ«·Â «œŒ«· „⁄·Ê„« 
void enterInfor(){
	FILE *file=fopen("degree.txt","a+");
	FILE *fileBin=fopen("Bdegree.bin","ab");

	struct student x;
	int c;

			// › Õ „·› ‰’Ì Ê„·› À‰«∆Ì
	if(file == NULL || fileBin == NULL){ 		
		printf("File eerror!\n");
		return;
	}


		printf("_____________________________________________________________\nInformation of Student number  :\n");

		printf("Student name :");

		while ((c = getchar()) != '\n' && c != EOF);

		fgets(x.name,100,stdin);

		printf(" the Acadimac Number :");
		scanf("%d",&x.AcadimicNamber);
		getchar();

		x.name[strcspn(x.name, "\n")] = 0;

	
		fprintf(file,"%s,%d", x.name, x.AcadimicNamber);

		printf("\nEnter the degree of every subjects :\n");

		for (int j=0;j<6;j++){
			printf("Subject %d :",j+1);

			do{
				scanf("%d", &x.degree[j]);

				if (x.degree[j] > 100 || x.degree[j] < 0) {
					printf("Error: enter degree between 0 and 100\n");
				}
			} while (x.degree[j] > 100 || x.degree[j] < 0);

			fprintf(file,",%d", x.degree[j]);
		}


		fprintf(file,",\n");

		fwrite(&x, sizeof(struct student), 1, fileBin);
	

	fclose(file);
	fclose(fileBin);
}
		
		//========= œ«·Â »ÕÀ ⁄‰ 
void search(){

	struct student s;
	FILE *fileBin = fopen("Bdegree.bin","rb");

	int id, ch, found = 0;
	char name[100];

	if (fileBin == NULL){
		printf("Error: cannot open file!\n");
		return;
	}
		//======== «Œ Ì«— ÿ—ÌﬁÂ «·»ÕÀ »«·—ﬁ„ «·«ﬂ«œÌ„Ì «Ê «·«”„ 
	printf("Enter '1' to search by Academic Number\n");
	printf("Enter '2' to search by Name\n");
	scanf("%d", &ch);

	switch (ch){

		case 1:

			printf("Enter Academic Number:\n");
			scanf("%d", &id);

			rewind(fileBin);

			while(fread(&s, sizeof(struct student), 1, fileBin)){

				if (id == s.AcadimicNamber){

					printf("\n===== Student Found =====\n");
					printf("Name: %s\nID: %d\n", s.name,s.AcadimicNamber);

					for(int i = 0; i < 6; i++) {
						printf("Subject %d: %d\n", i+1, s.degree[i]);
					}

					found = 1;
					break;
				}
			}

			if(!found)
				printf("Not found!\n");

			break;

		case 2:
			int c;
			while ((c = getchar()) != '\n' && c != EOF);

			printf("Enter Name:\n");
			fgets(name, 100, stdin);

			name[strcspn(name, "\n")] = 0;

			rewind(fileBin);

			while(fread(&s, sizeof(struct student), 1, fileBin)){

				s.name[strcspn(s.name, "\n")] = 0;

				if (strcmp(name, s.name) == 0){

					printf("\n===== Student Found =====\n");
					printf("Name: %s\nID: %d\n", s.name, s.AcadimicNamber);

					for(int i = 0; i < 6; i++) {
						printf("Subject %d: %d\n", i+1, s.degree[i]);
					}

					found = 1;
					break;
				}
			}

			if(!found)
				printf("Not found!\n");

			break;

		default:
			printf("Invalid choice!\n");
	}

	fclose(fileBin);
}
		
		//======== œ«·Â ⁄—÷ «·»Ì«‰« 
void show() {

	FILE *fileBin=fopen("Bdegree.bin","rb");

	if (fileBin == NULL) {
		printf("\nNo binary data found. Add students first.\n");
		return;
	}

	struct student s;

	printf("\n%-20s | %-10s | %-20s\n", "Name", "ID", "Degrees");
	printf("=======================================================\n");

	while (fread(&s, sizeof(struct student), 1, fileBin)) {

		printf("%-20s | %-10d | ", s.name, s.AcadimicNamber);

		for (int i = 0; i < 6; i++)
			printf("%d ,", s.degree[i]);

		printf("\n");
	}

	fclose(fileBin);
}

