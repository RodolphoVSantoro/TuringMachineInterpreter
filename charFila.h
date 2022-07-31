typedef struct List Node;
struct List{
	char v;
	Node *prox;
};

typedef struct{
	Node *ini, *fim;
}Fila;

typedef struct Pilha{
	Node *top;
}Pilha;

Node *cria(char v, Node *prox){
	Node* n = (Node*)malloc(sizeof(Node));
	n->v = v;
	n->prox = prox;
	return n;
}

void libera(Node *l){
	while(l){
		Node *tmp=l->prox;
		free(l);
		l=tmp;
	}
}

Fila* criaFila(){
	Fila *f = (Fila*)malloc(sizeof(Fila));
	f->ini=f->fim=NULL;
	return f;
}

bool vazia(Fila *f){
	return f->ini==NULL;
}

void insere(char v, Fila *f){
	Node* n = cria(v,NULL);
	if(vazia(f)) f->ini=n;
	else f->fim->prox=n;
	f->fim=n;
}

char retira(Fila *f){
	Node *tmp=f->ini;
	f->ini=f->ini->prox;
	char v=tmp->v;
	free(tmp);
	if(vazia(f)) f->fim=NULL;
	return v;
}

void libera(Fila *&f){
	libera(f->ini);
	free(f);
	f=NULL;
}

Pilha* criaPilha(){
	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->top=NULL;
	return p;
}

bool vazia(Pilha *p){
	return p->top==NULL;
}

void push(char v, Pilha *p){
	Node *n = cria(v,p->top);
	p->top=n;
}

int pop(Pilha *p){
	Node *tmp = p->top;
	int v = tmp->v;
	p->top=tmp->prox;
	free(tmp);
	return v;
}

void libera(Pilha *&p){
	libera(p->top);
	free(p);
	p=NULL;
}

int pilha2Int(Pilha *p){
	int e=1,r=0;
	Node *tmp=p->top;
	while(tmp){
		r+=(tmp->v-'0')*e;
		e*=10;
		tmp=tmp->prox;
	}
	return r;
}