#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//sudah
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
    int jumlahlaki = 0, jumlahcewek = 0;
    int i = 0;
    data nama_mahasiswa[1000];
    data nomor[1000];
    data tahun[1000];
    kelamin jenis_kelamin[1000];
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

            token = strtok(NULL, "|");
            strncpy(nomor[i].nim, token, sizeof(nomor[i].nim) - 1);

            token = strtok(NULL, "|");
            tahun[i].year = atoi(token);

            token = strtok(NULL, "|");
            if (strcmp(token, "MALE") == 0)
            {
                jenis_kelamin[i] = 0;
            }
            if (strcmp(token, "FEMALE") == 0)
            {
                jenis_kelamin[i] = 1;
            }

            if (jenis_kelamin[i] == 0)
            {
                jumlahlaki++;
            }

            else if (jenis_kelamin[i] == 1)
            {
                jumlahcewek++;
            }
            
            i++;
        }
    }
    printf("%d|%d", jumlahlaki, jumlahcewek);
}