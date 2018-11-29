#ifndef ETAPE3
#define ETAPE3

#define MAX_SIZE_MESSAGE_CODE 32
#define MAX_SIZE_URI 500
#define MAX_SIZE_METHOD 11
#define MAX_MESSAGE_BODY_SIZE 2000000
#define MAX_RES_SIZE 2020000
#define MAX_EXT_SIZE 20
#define MAX_VALUE_SIZE 2000
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)
#define MAXCLIENT 10
#define server_root "/root/Documents/site"
#define server_root_l 20

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include "abnf.h"

typedef struct {
	char *buf;				/**< buf Un pointeur vers le message recu */
	unsigned int len;			/**< len La longueur du message recu */
	unsigned int clientId;			/**< clientId identifiant du client, recu dans une requete, doit etre recopier dans la reponse correspondante*/
	struct sockaddr_in *clientAddress; 	/**< iclientAddress pointeur vers une structure permettant de recuperer l'adresse IP et le port du client HTTP */
} message;

typedef enum	Methode {
    POST, GET, PUT, OPTIONS, HEAD, DELETE, CONNECTIONS, TRACE, NUL
} Methode;
typedef enum	Langage {
    /*aa, ab, ae, af, ak, am, an, ar, as, av, ay, az,
    ba, be, bg, bh, bi, bm, bn, bo, br, bs,
    ca, ce, ch, co, cr, cs, cu, cv, cy,
    da, de, dv, dz,
    ee, el, en, eo, es, et, eu,
    fa, ff, fi, fj, fo, fr, fy,
    ga, gd, gl, gn, gu, gv,
    ha, he, hi, ho, hr, ht, hu, hy, hz,
    ia, id, ie, ig, ii, ik, in, io, is, it, iu, iw,
    ja, ji, jv, jw,
    ka, kg, ki, kj, kk, kl, km, kn, ko, kr, ks, ku, kv, kw, ky,
    la, lb, lg, li, ln, lo, lt, lu, lv,
    mg, mh, mi, mk, ml, mn, mo, mr, ms, mt, my,
    na, nb, nd, ne, ng, nl, nn, no, nr, nv, ny,
    oc, oj, om, Or, os,								Or au lieu de or
    pa, pi, pl, ps, pt,
    qu,
    rm, rn, ro, ru, rw,
    sa, sc, sd, se, sg, sg, sh, si, sk, sl, sm, sn, so, sq, sr, ss, st, su, sv, sw,
    ta, te, tg, th, ti, tk, tl, tn, to, tr, ts, tt, tw, ty,
    ug, uk, ur, uz,
    ve, vi, vo,
    wa, wo,
    xh,
    yi, yo,
    za, zh, zu,
    
    aaa, aab, aac, aad, aae*/
    
    fr, us
    
} Langage;
typedef struct	Champ Champ;
struct			Champ {
	char valeur[MAX_VALUE_SIZE];
	int v_l;
	Champ *next;
};
typedef struct	Champs {
	Champ* cookie;
	Champ* content_length;
	Champ* content_type;
	Champ* transfer_encoding;
	Champ* host;
	Champ* referer;
	Champ* user_agent;
	Champ* accept; /*Sera ensuite un champ Champ_accept*/
	Champ* accept_encoding;
	Champ* connection;
	
	/*facultatif*/
	/*Champ_accept_language* accept_language;*/
	
	Champ* date;
	Champ* server;
	Champ* location;
} Champs;
typedef struct	ReqInfo {
	Methode method;
	char URL[MAX_SIZE_URI];
	int u_l;
	int version[2];

	char ext[MAX_EXT_SIZE];
	int l_ext;
} ReqInfo;
typedef struct	ResInfo {
	int code;
	char message_code[MAX_SIZE_MESSAGE_CODE];
	int m_l;
	int version[2];
} ResInfo;
typedef struct	StructInfoReq {
	ReqInfo *req;
	Champs *c;
	char message[MAX_MESSAGE_BODY_SIZE];
	int m_l;
} StructInfoReq;
typedef struct	StructInfoRes {
	ResInfo *res;
	Champs *c;
	char message[MAX_MESSAGE_BODY_SIZE];
	int m_l;
} StructInfoRes;
typedef struct	Contenu {
	char* contenu;
	int l_c;
} Contenu;
typedef struct	Accept_Contenu Accept_Contenu;
struct			Accept_Contenu { /*Utilisé pour les champs Accept, Accept_language, ...*/
	float q;
	char* c;
	int l;
	Accept_Contenu* next;
};
typedef struct	Champ_accept Champ_accept;
struct			Champ_accept {
	Accept_Contenu a;
	Champ_accept* next;
};
typedef struct	Champ_accept_language Champ_accept_language;
struct			Champ_accept_language {
	Accept_Contenu a;
	Champ_accept_language* next;
};
typedef struct	Methodes Methodes;
struct			Methodes {
	Methode m;
	Methodes* next;
};
typedef struct	Langages Langages;
struct			Langages {
	Langage m;
	Langages* next;
};
typedef struct	Config {
	Methodes *m;
	Langages *l;
}Config;
typedef struct	Configs Configs;
struct			Configs {
	char *path;
	int l;
	Config* c;
	Configs* next;
};

/*VARIABLES GLOBALES*/
Configs config; /*Contient les moyens (méthodes et langages) d'accéder à une ressource*/
int semant_ok;  /*Initialisée à 1 au début de chaque analyse*/
char tampon[MAX_SIZE_URI];   /*Inutilisé ?*/
int l_tampon;
StructInfoReq i_req;    /*Remplie grâce à la requête, on se servira de cette structure pour prendre des décisions*/
StructInfoRes i_res;    /*Sert de base pour générer la réponse*/
char *c;    /*Récupération de la requête*/
int l;
int l_res;  /*Génération de la réponse*/
char* c_res;
char c_rep[MAX_SIZE_URI]; /*URL normalisée*/
int l_rep;
char c_complet[MAX_SIZE_URI]; /*URL normalisée et complétée*/
int l_complet;

/*PROTOTYPES*/

void ajout_fichier();
char *jourdesemaine(int,int,int);
void ajoutLocation();
void ajoutServeur();
int concat_chaine(char*,int,char*,int);
void config_init();
void ecrase_fichier();
int fonction4();
void recup_fichier();
void suppr_fichier();
void ajoutContentLength();
void ajoutContentType();
int zeros(int);
int longueur(int);
char recup_dernier_chiffre(int);
int power(int,int);
void ajoutMessageCode();
int fonction56();
void cb_method(char*,int);
void cb_request_target(char*,int);
void cb_http_version(char*,int);
void cb_cookie_string(char*,int);
void cb_content_length(char*,int);
void cb_transfer_encoding(char*,int);
void cb_Host(char*,int);
void cb_referer(char*,int);
void cb_user_agent(char*,int);
void cb_accept(char*,int);
void cb_accept_encoding(char*,int);
void cb_connection(char*,int);
void cb_URL(char*,int);
int compare(char*,int,char*,int);
int fonction3();
int fonctionx();
int norm_URL(int,char*,char*);
void recup_ext();
void remplissageStruct(char*,int);
void semantique(char*,int);
int bissextile(int);

int est_Host(char*,int,char*,int,void (*callback)());
message *getRequest(short int port);
char* itoa(int,char*,int);

void freeRequest(message *r); 
void sendReponse(message *r); 
void requestShutdownSocket(int i); 
#endif
