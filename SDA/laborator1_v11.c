// 11.	Să se creeze fişierul ghidul telefonic.
// Să se selecteze şi să se introducă într-un fişier separat datele referitor la abonaţii,
// posesori de telefoane, numerele cărora încep cu două cifre indicate. 

#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct GhidTelefonic
{
	char prenume[40], nume[40], patronimic[40];
	struct Adresa
	{
		char strada[20];
		char nr[4];
		char apartament[4];
	} adr;
	char nr_telefon[12];
};

FILE *open_file()
{
	FILE *cfPtr;
	if ((cfPtr = fopen("clients.dat", "a+")) == NULL)
	{
		printf("Fişierul nu poate fi deschis\n");
		return 0;
	}
	return cfPtr;
}

void write_entry_to_file()
{
	struct GhidTelefonic ghid;
	FILE *cfPtr = open_file();
	system("cls");
	printf("Introduceţi EOF pentru a finaliza introducerea.\n");
	printf("Introduceţi numele: ");
	scanf("%s", &ghid.nume);
	printf("Introduceţi prenumele: ");
	scanf("%s", &ghid.prenume);
	printf("Introduceţi patronimic: ");
	scanf("%s", &ghid.patronimic);
	printf("Introduceţi nr telefon: ");
	scanf("%s", &ghid.nr_telefon);

	printf("Introduceţi Adresa\n");
	printf("Introduceţi strada: ");
	scanf("%s", &ghid.adr.strada);
	printf("Introduceţi numarul casei: ");
	scanf("%s", &ghid.adr.nr);
	printf("Introduceţi nr apartament: ");
	scanf("%s", &ghid.adr.apartament);
	fprintf(cfPtr, "%s %s %s %s %s %s %s\n",
			ghid.nume, ghid.prenume, ghid.patronimic,
			ghid.nr_telefon,
			ghid.adr.strada, ghid.adr.nr, ghid.adr.apartament);
	fclose(cfPtr);
}

int line_count()
{
	FILE *f = open_file();
	int nr_rows = 0;
	char c;
	for (c = getc(f); c != EOF; c = getc(f))
		if (c == '\n') // Increment count if this character is newline
			nr_rows++;
	return nr_rows;
}

struct GhidTelefonic *get_data_from_file()
{
	FILE *f = open_file();
	struct GhidTelefonic *ghd = (struct GhidTelefonic *)calloc(line_count(f), sizeof(struct GhidTelefonic));
	int c = 0;
	while (fscanf(f, "%s %s %s %s %s %s %s",
				  &ghd[c].nume, &ghd[c].prenume, &ghd[c].patronimic, &ghd[c].nr_telefon,
				  &ghd[c].adr.strada, &ghd[c].adr.nr, &ghd[c].adr.apartament) > 0)
		c++;
	fclose(f);
	return ghd;
}

void print_data()
{
	struct GhidTelefonic *ghid = get_data_from_file();
	for (int i = 0; i < line_count(); i++)
	{
		printf("Numele: %s\nPrenumele: %s\nPatronimicul: %s\nNr Telefon: %s\nStrada: %s\nNr casei: %s\nNr apartament: %s\n", ghid[i].nume, ghid[i].prenume, ghid[i].patronimic, ghid[i].nr_telefon,
			   ghid[i].adr.strada, ghid[i].adr.nr, ghid[i].adr.apartament);
		printf("------------------------\n");
	}
	getch();
}

void new_file()
{
	FILE *f;
	if ((f = fopen("clients_separat.dat", "w")) == NULL)
	{
		printf("Fişierul nu poate fi creat\n");
		return;
	}

	char nr[3];
	printf("Introduceti cifrele: ");
	scanf("%s", &nr);

	struct GhidTelefonic *ghid = get_data_from_file();
	for (int i = 0; i < line_count(); i++)
	{
		char currentnr[3];
		strncpy(currentnr, ghid[i].nr_telefon,2);

		if (strncmp(nr,currentnr,2) == 0){	
			fprintf(f, "%s %s %s %s %s %s %s\n",
					ghid[i].nume, ghid[i].prenume, ghid[i].patronimic,
					ghid[i].nr_telefon,
					ghid[i].adr.strada, ghid[i].adr.nr, ghid[i].adr.apartament);
		}
	}
	fclose(f);
}

int main()
{
	int request;
	while (request != 4)
	{
		system("cls");
		printf("Introduceţi interpelarea\n"
			   "1 – Adauga abonat\n"
			   "2 – Afiseaza abonati\n"
			   "3 – Introdu in fisier separat abonatii cu numerele care incep cu cifrele indicate\n"
			   "4 - Iesire\n");
		scanf("%d", &request);

		switch (request)
		{
		case 1:
			write_entry_to_file();
			break;
		case 2:
			print_data();
			break;
		case 3:
			new_file();
			break;
		}
	}
}
