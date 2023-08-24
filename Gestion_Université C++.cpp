#include <iostream>
using namespace std;

//classe universite
class universite {
    protected :
        int id ;
    public :
        universite(int ID)
        {
            id=ID ;
        }
    void saisie()
    {
        cout<<"-Veuillez saisir votre Id : " ;
        cin>>id ;
        while( id < 1000 || id > 100000 )
        {
            cout<<"ID Invalid, Reessayer s'il vous plait \n" ;
            cout<<"-Veuillez saisir votre Id : " ;
            cin>>id ;
        }
    }
} ;

//classe Etudiant
class etudiant : public universite  {
    protected :
         string nom;
         string prenom ;
         string n_classe ;
         string n_filiere ;
         //date de naissance de l'etudiant
         int jour , mois , annee ;
         float m=0 ;
    public :
        etudiant( int ID, string n, string p, int j , int m , int an, string nf, string nc ) : universite(ID)
        {
            nom=n ;
            prenom=p ;
            jour = j ;
            mois = m ;
            annee = an ;
            n_filiere= nf ;
            n_classe=nc ;
        }

    void saisie()
    {
        universite::saisie() ;
        cout<<"-Veuillez saisir votre nom: " ;
        cin>>nom ;
        cout<<"-Veuillez saisir votre prenom: " ;
        cin>>prenom ;
        cout<<"-Veuillez saisir votre date de naissance \n" ;
        cout<<"-le jour : " ;
        cin>>jour ;
        while ( jour > 31 || jour <1 )
        {
          cout<<"jour invalid , Reessayer une autre fois !  \n" ;
          cout<<"-le jour : " ;
          cin>>jour ;
        }
        cout<< "-le mois : " ;
        cin>>mois ;
        while ( mois > 12 || mois <1 )
        {
          cout<<"Mois invalid , Reessayer une autre fois !  \n" ;
          cout<<"-le mois : " ;
          cin>>mois ;
        }
        cout<<"-L'annee : " ;
        cin>>annee ;
        while ( annee > 9999 || annee <1000 )
        {
          cout<<"Annee invalid , Reessayer une autre fois !  \n" ;
          cout<<"-L'annee : " ;
          cin>>annee ;
        }
        cout<<"-Veuillez saisir votre filiere : " ;
        cin>>n_filiere ;
        cout<<"-Veuillez saisir votre classe : " ;
        cin>>n_classe ;
    }

    // calcul de la moyenne de l'etudiant
    void calcul_moyenne()
    {
        int nombre_matiere ;
        float note ;
        float co_m ;
        int i;
        float moy ;
        float s=0 ;
        cout<<"-Veuillez saisir le nombre des matieres : " ;
        cin>>nombre_matiere ;
        float t_moy[nombre_matiere] ;
        for(i=0; i<nombre_matiere; i++)
        {
            cout<<"-Veuillez saisir la note du matiere num-"<< (i+1)<<" : "  ;
            cin>>note;
            while(note<1 || note> 20 )
            {
                cout<<"Note invalid, Reessayer ! \n" ;
                cout<<"-Veuillez saisir la note du matiere num-"<< (i+1)<<" : "  ;
                cin>>note;
            }
            cout<<"-Veuillez saisir la coefficient du matiere num-"<<(i+1)<<" : " ;
            cin>>co_m ;
            moy = note * co_m ;
            t_moy[i] = moy ;
            s=s+co_m ;
        }
        for(i=0; i<=nombre_matiere; i++)
        {
            m+=(t_moy[i])/s ;
        }
    }

    void display_etd()
    {
        cout<<"-Id : "<<id<< endl ;
        cout<<"-Nom : "<<nom << endl ;
        cout<<"-Prenom : "<<prenom<< endl ;
        cout<<"-Date de naissance : " ;
        cout << jour <<"/"<< mois<< "/" << annee << endl ;
        cout<<"-Filiere : "<<n_filiere<< endl ;
        cout<<"-Classe : " << n_classe<< endl ;
        cout<<"-Moyenne generale : " << m << endl  ;
        cout<<"\n" ;
    }
} ;

//classe Enseignant
class enseignant : public universite  {
    protected :
         string nom_enseignant;
         string prenom_enseignant ;
         string nom_matiere ;
         float salaire ;
    public :
        enseignant( int ID, string ne, string pe, string nm ) : universite(ID)
        {
            nom_enseignant=ne ;
            prenom_enseignant=pe ;
            nom_matiere= nm ;
        }

    void saisie()
    {
        universite::saisie() ;
        cout<<"-Veuillez saisir votre nom : " ;
        cin>>nom_enseignant ;
        cout<<"-Veuillez saisir votre prenom : " ;
        cin>>prenom_enseignant ;
        cout<<"-Veuillez saisir la matiere que vous enseignez : " ;
        cin>>nom_matiere ;
    }

    void calcul_salaire()
    {
        float prix_heure ;
        float nombre_heure ;
        cout<<"-Veuillez saisir le prix d'heure : " ;
        cin>>prix_heure ;
        cout<<"-Veuillez saisir le nombre d'heure par mois : " ;
        cin>>nombre_heure ;
        salaire = prix_heure * nombre_heure ;
    }

    void display_eng()
    {
        cout<<"-ID :"<<id<< endl ;
        cout<<"-Nom :"<<nom_enseignant << endl ;
        cout<<"-Prenom :"<<prenom_enseignant<< endl ;
        cout<<"-Matiere a enseigner :"<<nom_matiere<<endl ;
        cout<<"-Salaire : " << salaire << endl ;
        cout<<"\n" ;
    }
} ;

//classe matiére
class matiere  {
    protected :
         string nom_matiere;
         float note_matiere1 ;
         float note_matiere2 ;
         float coefficient1  ;
         float coefficient2 ;
         float moy ;
    public :
        matiere(string nm, float cf1, float nt1, float nt2, float cf2  )
        {
            nom_matiere = nm ;
            note_matiere1=nt1  ;
            note_matiere2=nt2  ;
            coefficient1 = cf2 ;
            coefficient2= cf2 ;
        }

    void saisie_m()
    {
        cout<<"-Veuillez saisir le nom du matiere : " ;
        cin>>nom_matiere ;
        cout<<"-Veuillez saisir la premiere note du matiere : " ;
        cin >>note_matiere1 ;
        while(note_matiere1 < 1 || note_matiere1> 20 )
        {
            cout<<"Premiere note invalide, Reessayer ! \n" ;
            cout<<"-Veuillez saisir la premiere note du matiere : " ;
            cin >>note_matiere1 ;
        }
        cout<<"-Veuillez saisir la deuxieme note du matiere : " ;
        cin >>note_matiere2 ;
        while(note_matiere2 < 1 || note_matiere2> 20 )
        {
            cout<<"Deuxieme note invalide, Reessayer ! \n" ;
            cout<<"-Veuillez saisir la premiere note du matiere : " ;
            cin >>note_matiere1 ;
        }
        cout<<"-Veuillez saisir le coefficient du premiere note : " ;
        cin>>coefficient1 ;
        while (coefficient1<0)
        {
            cout<<"Coefficient invalide, Reessayer ! \n" ;
            cout<<"-Veuillez saisir le coefficient du premiere note : " ;
            cin>>coefficient1 ;
        }
        cout<<"-Veuillez saisir le coefficient du deuxieme note : " ;
        cin>>coefficient2 ;
        while (coefficient2<0)
        {
            cout<<"Coefficient invalide, Reessayer ! \n" ;
            cout<<"-Veuillez saisir le coefficient du deuxieme note : " ;
            cin>>coefficient2 ;
        }
    }
    void calcul_moyenne_matiere()
    {
        float s1, s2 ;
        s1=note_matiere1*coefficient1;
        s2=note_matiere2*coefficient2;
        moy= (s1+s2)/(coefficient1+coefficient2) ;
        cout<<"\nLa moyenne du "<<nom_matiere<<" est : " <<moy<<"\n" ;
    }

    void display_m()
    {
        cout<<"-Nom du matiere :"<<nom_matiere ;
        cout<<"\n-Premiere note du " <<nom_matiere<<" est : "<< note_matiere1 << ", sa coefficient : " << coefficient1 ;
        cout<<"\n-Deuxieme note du " <<nom_matiere<<" est : "<< note_matiere2 <<", sa coefficient :" << coefficient2  ;
        cout<<"-Moyenne generale du "<< nom_matiere << " est : " << moy  ;
        cout<<"\n" ;
    }
} ;

//classe departement
class departement  {
    protected :
         string nom_departement;
         string adresse   ;
         string chef_departement ;
         float revenu ;
    public :
        departement( string nd, string adr )
        {
            nom_departement = nd  ;
            string adresse = adr ;
        }

    void saisie_d()
    {
        cout<<"-Veuillez saisir le nom du departement : " ;
        cin>>nom_departement ;
        cout<<"-Veuillez saisir l'adresse du departement : " ;
        cin>>adresse  ;
    }

    void revenu_chef_departement()
    {
        float salaire ;
        cout<<"-Veuillez saisir le nom du chef de departement : " ;
        cin>>chef_departement ;
        cout<<"-Veuillez saisir le salaire de "<<chef_departement<<" : " ;
        cin>>salaire ;
        revenu= salaire * 12 ;
    }

    void display_d()
    {
        cout<<"-Nom du departement :"<<nom_departement<< endl ;
        cout<<"-L'adresse du departement :"<<adresse<< endl ;
        cout<<"-Nom du Chef de departement :" << chef_departement<< endl ;
        cout<<"-Revenu annuel de "<<chef_departement<< " est : " << revenu << endl ;
        cout<<"\n" ;
    }
} ;


//classe etage
class etage {
    protected :
         int num_etage ;
    public :
        etage( int netg)
        {
           num_etage = netg ;
        }

    void saisie_et()
    {
        cout<<"-Veuillez saisir le numero d'etage : " ;
        cin>>num_etage ;
        while(num_etage<1)
        {
            cout<<"Num d'etage invalide, Reessayer ! \n" ;
            cout<<"-Veuillez saisir le numero d'etage : " ;
            cin>>num_etage ;
        }
    }

    void disponibilite_salle()
    {
        int i,k,d,nd  ;
            cout<<"-Veuillez saisir combien de salle disponible en cet etage : " ;
            cin>> d;
            int salle_dispo[d] ;
            for(i=0; i<d ; i++)
            {
                cout<<"-Veuillez saisir le num du salle disponible n-"<<(i+1)<< " : "  ;
                cin>>salle_dispo[i] ;
            }

            cout<<"-Veuillez saisir combien de salle non disponible en cet etage : " ;
            cin>> nd;
            int salle_non_dispo[nd] ;
            for(k=0; k<nd ; k++)
            {
                cout<<"-Veuillez saisir  le num du salle non disponible n-" << (k+1) << " : " ;
                cin>>salle_non_dispo[k] ;
            }
            cout<<"-Les salles disponibles en cet etage sont :\n" ;
            for(i=0; i<d ; i++)
            {
                cout<<"- "<< salle_dispo[i] <<" - " <<" " ;
            }
            cout<<"\n-Les salles non disponibles en cet etage sont :\n" ;
            for(k=0; k<nd ; k++)
            {
                cout<<"- "<<salle_non_dispo[k] <<" - " <<" "  ;
            }
            cout<<"\n" ;
        }

    void display_et()
        {
            cout<<"-Le numero d'etage :"<<num_etage ;
            cout<<"\n" ;
        }


} ;

//classe salle
class salle  {
    protected :
         int num_salle ;
         int num_etage ;

    public :
        salle(int s, int numet )
        {
            num_salle = s ;
            num_etage = numet ;
        }

    void saisie_s()
    {
        cout<<"-Veuillez saisir le numero de l'etage : " ;
        cin>>num_etage ;
        while(num_etage<1)
        {
            cout<<"Num d'etage invalide, Reessayer ! \n" ;
            cout<<"-Veuillez saisir le numero de l'etage : " ;
            cin>>num_etage ;
        }
        cout<<"-Veuillez saisir le numero de la salle : " ;
        cin>>num_salle ;
    }

    void ajout()
    {
        string nom_en ;
        string nom_ma ;
        int heure_debut ;
        int heure_fin ;
        int jour , mois , annee ;
        cout<<"-Veuillez saisir  le nom de l'enseignant : " ;
        cin>>nom_en ;
        cout<<"-Veuillez saisir le nom de la matiere pour l'enseigannt " << nom_en << ":"  ;
        cin>> nom_ma ;
        cout<<"-Veuillez saisir la Date : \n" ;
        cout<<"-le jour : " ;
        cin>>jour ;
        while ( jour > 31 || jour <1 )
        {
          cout<<"jour invalid , Reessayer une autre fois !  \n" ;
          cout<<"-le jour : " ;
          cin>>jour ;
        }
        cout<< "-le mois : " ;
        cin>>mois ;
        while ( mois > 12 || mois <1 )
        {
          cout<<"Mois invalid , Reessayer une autre fois !  \n" ;
          cout<<"-le mois : " ;
          cin>>mois ;
        }
        cout<<"-L'annee : " ;
        cin>>annee ;
        while ( annee > 9999 || annee <1000 )
        {
          cout<<"Annee invalid , Reessayer une autre fois !  \n" ;
          cout<<"-L'annee : " ;
          cin>>annee ;
        }
        cout<<"-Veuillez saisir l'heure de debut du seance : " ;
        cin >>heure_debut ;
        cout<<"-Veuillez saisir l'heure de la fin du seance : " ;
        cin>>heure_fin ;
        cout<<"-L'enseignant "<<nom_en<<" a une seance de "<<nom_ma<< ",de "<<heure_debut<<"h "<<"a "<<heure_fin<<"h " ;

    }

    void display_s()
    {
        cout<<"-Numero de l'etage : " << num_etage << endl ;
        cout<<"\n" ;
        cout<<"-Numero de la salle :"<<num_salle<< endl ;
        cout<<"\n" ;
    }
} ;

//classe classe
class classe {
    protected :
         string nom_classe ;
         int nombre_etudiant ;
    public :
        classe( string nc , int nt )
        {
           nom_classe = nc ;
           nombre_etudiant = nt ;
        }

    void saisie_c()
    {
        cout<<"-Veuillez saisir le nom de la classe  : " ;
        cin>>nom_classe ;
        cout<<"-Veuillez saisir le nombre l'etudiant pour cette classe : " ;
        cin>>nombre_etudiant ;
    }

    void moyenne_classe()
    {
        string nom_etudiant ;
        float moyenne_etudiant ;
        int j , i ;
        float m = 0;
        float moyenne ;
        string t[nombre_etudiant];
        float t2[nombre_etudiant] ;
        for(i=0; i<nombre_etudiant;i++)
            {
            cout<<"-Veuillez saisir le nom de l'etudiant num " << i+1 << " : " ;
            cin>>nom_etudiant ;
            t[i] = nom_etudiant ;
            }

        for(j=0; j< i ; j++)
            {
            cout<<"-Veuillez saisir la moyenne de l'etudiant num"<<j+1<<" : "  ;
            cin>>moyenne_etudiant;
            t2[j] = moyenne_etudiant ;
            }

         for(j=0; j< nombre_etudiant ; j++)
            {
                 m= m + t2[j] ;
            }
        moyenne = m / nombre_etudiant ;
        cout<<"Noms\n";
        cout<<"\n" ;
        for(i=0;i<nombre_etudiant;i++)
        {
            cout<<t[i]<<"\n"<< endl ;  ;
        }
        cout<<"Les moyennes\n";
        cout<<"\n";
        for(j=0;j<nombre_etudiant;j++)
        {
            cout<<t2[j]<<"\n"<<endl ;
        }
        cout<<"\n" ;
        cout<<"-La moyenne generale du Classe "<<nom_classe<<" est : "<<moyenne<<"\n" ;
    }


    void display_c()
    {
        cout<<"-Nom de la classe :"<<nom_classe<< endl ;
        cout<<"-Nombre d'etudiant pour cette classe : "<< nombre_etudiant  ;
        cout<<"\n" ;
    }
} ;

//classe filiere
class filiere  {
    protected :
         string nom_filiere  ;
         int nombre_classe ;
    public :
        filiere( string fl , int nc )
        {
           nom_filiere= fl  ;
           nombre_classe = nc ;
        }

    void saisie_f()
    {
        cout<<"-Veuillez saisir le nom de la filiere  : " ;
        cin>>nom_filiere ;
        cout<<"-Veuillez saisir le nombre des classes pour cette filiere : " ;
        cin>>nombre_classe ;
    }

    void date_examen()
    {
        int i, k ;
        string nom_classe ;
        int num_semestre ;
        int nombre_matiere;
        string nom_matiere ;
        int heure_debut ;
        int heure_fin ;
        int jour , mois , annee ;
        cout<<"-Veuillez saisir le num du Semestre : ";
        cin>>num_semestre ;
        for(i=0;i<nombre_classe;i++)
        {
            cout<<"-Veuillez saisir le nom du classe : " ;
            cin>>nom_classe;
            cout<<"-Veuillez saisir le nombre des matieres pour l'examen : " ;
            cin>>nombre_matiere ;
            for(k=0;k<nombre_matiere;k++)
            {
                cout<<"-Veuillez saisir le nom du matiere : " ;
                cin>>nom_matiere ;
                cout<<"Date d'examen pour cette matiere : \n" ;
                cout<<"le jour : " ;
                cin>>jour ;
                cout<< "le mois : " ;
                cin>>mois ;
                cout<<"l'annee : " ;
                cin>>annee ;
                cout<<"-Veuillez saisir l'heure du debut de l'examen : " ;
                cin >>heure_debut ;
                cout<<"-Veuillez saisir l'heure de la fin d'examen : " ;
                cin>>heure_fin ;

            cout<<"-Num Semestre : "<<num_semestre<<endl ;
            cout<<"-La classe "<<nom_classe<<" a "<<nombre_matiere<<" examens : \n"<< endl ;
            cout<<"-L'examen num "<<k+1<<" :\n"<< endl ;
            cout<<nom_matiere<<" sera le : "<< jour <<"/"<< mois<< "/" << annee <<", de :"<<heure_debut<<"h a "<<heure_fin<<"h \n"<<endl ;
            }
        }
    }

    void display_f()
    {
        cout<<"-Nom du filiere :"<<nom_filiere<< endl ;
        cout<<"\n" ;
    }
} ;


int main ()
{
        cout<<"\t                     -Etudiant-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"\n" ;
        cout<<"La Saisie  \n" ;
        cout<<"-----------\n" ;
        etudiant e(0,"","",0,0,0,"","") ;
        e.saisie() ;
        cout<<"\n" ;
        cout<<"Calcul du moyenne generale pour l'etudiant \n" ;
        cout<<"-------------------------------------------\n" ;
        cout<<"\n" ;
        e.calcul_moyenne() ;
        cout<<"\n" ;
        cout<<"L'affichage de tout les informations de l'etudiant  \n" ;
        cout<<"--------------------------------------------------\n" ;
        cout<<"\n" ;
        e.display_etd() ;


        cout<<"\t                     -Enseignant-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie \n" ;
        cout<<"-----------\n" ;
        enseignant ensg(0,"","","") ;
        ensg.saisie() ;
        cout<<"\n" ;
        cout<<"Calcul du salaire de l'enseignant \n" ;
        cout<<"----------------------------------\n" ;
        cout<<"\n" ;
        ensg.calcul_salaire() ;
        cout<<"\n" ;
        cout<<"L'affichage de tout les informations de l'enseignant  \n" ;
        cout<<"-----------------------------------------------------\n" ;
        cout<<"\n" ;
        ensg.display_eng() ;


        cout<<"\t                     -Matiere-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie \n" ;
        cout<<"-----------\n" ;
        matiere m("",0.0,0.0,0.0,0.0) ;
        m.saisie_m() ;
        cout<<"\n" ;
        cout<<"Calcul du moyenne de la matiere \n" ;
        cout<<"--------------------------------- \n" ;
        cout<<"\n" ;
        m.calcul_moyenne_matiere() ;
        cout<<"\n" ;
        cout<<"L'affichage de tout les informations du matiere  \n" ;
        cout<<"------------------------------------------------- \n" ;
        m.display_m() ;


        cout<<"\n" ;
        cout<<"\t                     -Departement-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie  \n" ;
        cout<<"-----------\n" ;
        departement dp("","") ;
        dp.saisie_d() ;
        cout<<"\n" ;
        cout<<"Calcul de revenu du chef de departement \n" ;
        cout<<"----------------------------------------- \n" ;
        dp.revenu_chef_departement() ;
        cout<<"\n" ;
        cout<<"L'affichage de tout les informations du departement  \n" ;
        cout<<"----------------------------------------------------- \n" ;
        dp.display_d() ;


        cout<<"\t                     -Etage-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie  \n" ;
        cout<<"-----------\n" ;
        etage eg(0)  ;
        eg.saisie_et() ;
        cout<<"\n" ;
        eg.display_et() ;
        cout<<"\n" ;
        cout<<"Disponibilite des Salles \n" ;
        cout<<"-------------------------- \n" ;
        eg.disponibilite_salle() ;


        cout<<"\n" ;
        cout<<"\t                     -Salle-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie  \n" ;
        cout<<"-----------\n" ;
        salle s(0,0) ;
        s.saisie_s() ;
        cout<<"\n" ;
        s.display_s() ;
        cout<<"\n" ;
        cout<<"Ajout d'une seance a la salle \n" ;
        cout<<"------------------------------- \n" ;
        s.ajout() ;
        cout<<"\n" ;



        cout<<"\n\t                     -Classe-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie  \n" ;
        cout<<"-----------\n" ;
        classe c("",0) ;
        c.saisie_c() ;
        cout<<"\n" ;
        c.display_c() ;
        cout<<"\n" ;
        cout<<"Calcul du moyenne general de classe  \n" ;
        cout<<"---------------------------------------\n" ;
        c.moyenne_classe() ;



        cout<<"\t                     -Filiere-\n" ;
        cout<<"\t          **********************************\n" ;
        cout<<"La Saisie : \n" ;
        cout<<"-----------\n" ;
        filiere f("",0) ;
        f.saisie_f() ;
        cout<<"\n" ;
        f.display_f() ;
        cout<<"Ajout des examens pour cette filiere \n" ;
        cout<<"--------------------------------------\n" ;
        f.date_examen() ;


return 0 ;
}
