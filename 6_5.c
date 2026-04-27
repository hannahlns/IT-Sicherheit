#include <stdio.h>
#include <string.h>
#include <malloc.h>

static char *cipher;

static char *xor( char *a, char *secret )
{
    char *ptr, *sptr;
    int secret_length = strlen( secret );

    if( strlen(a) > strlen(secret) ) {
        printf("WARNING: secret too small...\n");
    }

    cipher = malloc( strlen(a) );
    if (cipher==NULL) {
        perror("cipher-buffer");
        return NULL;
    }

    // TODO: Ab hier ergaenzen
    for (int i = 0; i < strlen(a); i++) {
        cipher[i] = a[i] ^ secret[i % secret_length];
    }

    return cipher;
}

int main( int argc, char **argv )
{
    char *ptr;
    int i;

    if( argc!=3 ) {
        printf("usage: %s cleartext key\n", argv[0] );
        return -1;
    }

    ptr = xor( argv[1], argv[2] );
    if (ptr) {
        for( i=strlen(argv[1]); i; ptr++, i-- ) {
            printf("0x%02x ", (unsigned char)*ptr );
        }
        printf("\n");
        free( cipher );
    }

    return 0;
}
