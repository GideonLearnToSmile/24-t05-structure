#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    typedef enum
    {
        MALE,
        FEMALE
    } kelamin;

    typedef struct
    {
        char nama[20];
        char nim[20];
        int year;
        kelamin gender;
    } data;

    char input[1000];
    char perintah[10];
    data nama_mahasiswa[1000];
    data nomor[1000];
    data tahun[1000];
    int jumlahlaki = 0, jumlahcewek = 0;
    int i = 0;
    char namalaki[1000][20]; 
    char namacewek[1000][20]; 

    scanf("%s", perintah);

    if (strcmp(perintah, "register") == 0)
    {
        while (i >= 0)
        {
            scanf("%s", input);
            if (strcmp(input, "---") == 0)
            {
                break;
            }

            char *token = strtok(input, "|");
            strncpy(nama_mahasiswa[i].nama, token, sizeof(nama_mahasiswa[i].nama) - 1);
            nama_mahasiswa[i].nama[sizeof(nama_mahasiswa[i].nama) - 1] = '\0';

            token = strtok(NULL, "|");
            strncpy(nomor[i].nim, token, sizeof(nomor[i].nim) - 1);

            token = strtok(NULL, "|");
            tahun[i].year = atoi(token);

            token = strtok(NULL, "|");
            if (strcmp(token, "MALE") == 0)
            {
                nama_mahasiswa[i].gender = MALE;
            }
            else if (strcmp(token, "FEMALE") == 0)
            {
                nama_mahasiswa[i].gender = FEMALE;
            }

            if (nama_mahasiswa[i].gender == MALE)
            {
                strcpy(namalaki[jumlahlaki], nama_mahasiswa[i].nama);
                jumlahlaki++;
            }
            else if (nama_mahasiswa[i].gender == FEMALE)
            {
                strcpy(namacewek[jumlahcewek], nama_mahasiswa[i].nama);
                jumlahcewek++;
            }

            i++;
        }
    }

    printf("%d|%d\n", jumlahlaki, jumlahcewek);
    
    for (i = 0; i < jumlahlaki; i++)
    {
        printf("%s|", namalaki[i]);
    }
    printf("\n");

    for (i = 0; i < jumlahcewek; i++)
    {
        printf("%s|", namacewek[i]);
    }

    return 0;
}