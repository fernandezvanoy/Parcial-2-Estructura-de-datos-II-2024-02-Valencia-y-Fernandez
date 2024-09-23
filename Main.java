import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    
    public static void main (String []args) {

        Scanner sc = new Scanner(System.in);
        
        System.out.println("Seleccione como desea ver las rutas");

        System.out.println("Nodos: 1");
        System.out.println("Distancia: 2");
        System.out.println("Giros: 3");

        int opt = sc.nextInt();

        //creacion del grafo
        ArrayList<Via> mapa = new ArrayList<>();
        ArrayList<Nodo> minimapa = new ArrayList<>();

        //cracion de calles
        Via AvNutibara = new Via("AvNutibara");//7
        Via Transv39a = new Via("Transv39a");//4
        Via Transv39 = new Via("Transv39");//9
        Via Transv38 = new Via("Transv38");//5
        Via Transv37 = new Via("Transv37");//3
        Via Transv36 = new Via("Transv36");//3
        Via Transv35 = new Via("Transv35");//2
        Via Transv34 = new Via("Transv35");//2
        Via Carrera36 = new Via("Carrera36");//5

        Via Transv39cb = new Via("Transv39cb");//2
        Via Transv39ca = new Via("Transv39ca");//3
        Via Circ73b = new Via("Circ73b");//4
        Via Circ73a = new Via("Circ73a");//4
        Via Circ73 = new Via("Circ73");//8
        Via Circ72 = new Via("Circ72");//7
        Via Circ71 = new Via("Circ71");//4
        Via Clle33a = new Via("Clle33a");//5

        Via Clle35 = new Via("Clle35");//2


        for(int i = 0; i < 41; i++){
            minimapa.add(new Nodo(i));
        }

        //Conexiones de cada Nodo
        minimapa.get(0).getAdyacentes().add(minimapa.get(1));
        
        minimapa.get(1).getAdyacentes().add(minimapa.get(13));
        minimapa.get(1).getAdyacentes().add(minimapa.get(2));

        minimapa.get(2).getAdyacentes().add(minimapa.get(3));

        minimapa.get(3).getAdyacentes().add(minimapa.get(15));
        minimapa.get(3).getAdyacentes().add(minimapa.get(4));

        minimapa.get(4).getAdyacentes().add(minimapa.get(5));

        minimapa.get(5).getAdyacentes().add(minimapa.get(6));

        minimapa.get(6).getAdyacentes().add(minimapa.get(9));

        minimapa.get(10).getAdyacentes().add(minimapa.get(19));

        minimapa.get(11).getAdyacentes().add(minimapa.get(0));

        minimapa.get(12).getAdyacentes().add(minimapa.get(11));
        minimapa.get(12).getAdyacentes().add(minimapa.get(0));

        minimapa.get(13).getAdyacentes().add(minimapa.get(33));
        minimapa.get(13).getAdyacentes().add(minimapa.get(12));
        minimapa.get(13).getAdyacentes().add(minimapa.get(14));

        minimapa.get(14).getAdyacentes().add(minimapa.get(13));
        minimapa.get(14).getAdyacentes().add(minimapa.get(15));
        minimapa.get(14).getAdyacentes().add(minimapa.get(2));

        minimapa.get(15).getAdyacentes().add(minimapa.get(3));
        minimapa.get(15).getAdyacentes().add(minimapa.get(14));
        minimapa.get(15).getAdyacentes().add(minimapa.get(16));
        minimapa.get(15).getAdyacentes().add(minimapa.get(21));

        minimapa.get(16).getAdyacentes().add(minimapa.get(7));
        minimapa.get(16).getAdyacentes().add(minimapa.get(17));
        minimapa.get(16).getAdyacentes().add(minimapa.get(22));

        minimapa.get(17).getAdyacentes().add(minimapa.get(8));
        minimapa.get(17).getAdyacentes().add(minimapa.get(18));
        minimapa.get(17).getAdyacentes().add(minimapa.get(23));
        minimapa.get(17).getAdyacentes().add(minimapa.get(16));

        minimapa.get(18).getAdyacentes().add(minimapa.get(17));
        minimapa.get(18).getAdyacentes().add(minimapa.get(9));
        minimapa.get(18).getAdyacentes().add(minimapa.get(19));
        minimapa.get(18).getAdyacentes().add(minimapa.get(24));

        minimapa.get(19).getAdyacentes().add(minimapa.get(10));
        minimapa.get(19).getAdyacentes().add(minimapa.get(24));
        
        minimapa.get(20).getAdyacentes().add(minimapa.get(14));
        minimapa.get(20).getAdyacentes().add(minimapa.get(21));

        minimapa.get(21).getAdyacentes().add(minimapa.get(15));
        minimapa.get(21).getAdyacentes().add(minimapa.get(36));
        minimapa.get(21).getAdyacentes().add(minimapa.get(22));

        minimapa.get(22).getAdyacentes().add(minimapa.get(21));
        minimapa.get(22).getAdyacentes().add(minimapa.get(25));
        minimapa.get(22).getAdyacentes().add(minimapa.get(23));

        minimapa.get(23).getAdyacentes().add(minimapa.get(22));
        minimapa.get(23).getAdyacentes().add(minimapa.get(17));
        minimapa.get(23).getAdyacentes().add(minimapa.get(26));
        minimapa.get(23).getAdyacentes().add(minimapa.get(24));

        minimapa.get(24).getAdyacentes().add(minimapa.get(23));
        minimapa.get(24).getAdyacentes().add(minimapa.get(18));
        minimapa.get(24).getAdyacentes().add(minimapa.get(19));
        minimapa.get(24).getAdyacentes().add(minimapa.get(27));

        minimapa.get(25).getAdyacentes().add(minimapa.get(28));
        minimapa.get(25).getAdyacentes().add(minimapa.get(26));

        minimapa.get(26).getAdyacentes().add(minimapa.get(25));
        minimapa.get(26).getAdyacentes().add(minimapa.get(29));
        minimapa.get(26).getAdyacentes().add(minimapa.get(23));
        minimapa.get(26).getAdyacentes().add(minimapa.get(27));

        minimapa.get(27).getAdyacentes().add(minimapa.get(24));
        minimapa.get(27).getAdyacentes().add(minimapa.get(26));
        minimapa.get(27).getAdyacentes().add(minimapa.get(30));

        minimapa.get(28).getAdyacentes().add(minimapa.get(29));
        minimapa.get(28).getAdyacentes().add(minimapa.get(31));

        minimapa.get(29).getAdyacentes().add(minimapa.get(28));
        minimapa.get(29).getAdyacentes().add(minimapa.get(32));
        minimapa.get(29).getAdyacentes().add(minimapa.get(30));
        minimapa.get(29).getAdyacentes().add(minimapa.get(26));

        minimapa.get(30).getAdyacentes().add(minimapa.get(29));
        minimapa.get(30).getAdyacentes().add(minimapa.get(40));
        minimapa.get(30).getAdyacentes().add(minimapa.get(27));

        minimapa.get(31).getAdyacentes().add(minimapa.get(32));
        minimapa.get(31).getAdyacentes().add(minimapa.get(37));

        minimapa.get(33).getAdyacentes().add(minimapa.get(11));

        minimapa.get(34).getAdyacentes().add(minimapa.get(20));
        minimapa.get(34).getAdyacentes().add(minimapa.get(33));

        minimapa.get(35).getAdyacentes().add(minimapa.get(21));
        minimapa.get(35).getAdyacentes().add(minimapa.get(34));

        minimapa.get(36).getAdyacentes().add(minimapa.get(21));
        minimapa.get(36).getAdyacentes().add(minimapa.get(35));

        minimapa.get(37).getAdyacentes().add(minimapa.get(36));

        minimapa.get(38).getAdyacentes().add(minimapa.get(37));

        minimapa.get(39).getAdyacentes().add(minimapa.get(38));

        minimapa.get(40).getAdyacentes().add(minimapa.get(39));
        minimapa.get(40).getAdyacentes().add(minimapa.get(38));



        //Añade las distancias a cada nodo
        minimapa.get(0).getDistancias().add(52);

        minimapa.get(1).getDistancias().add(100);
        minimapa.get(1).getDistancias().add(100);

        minimapa.get(2).getDistancias().add(94);

        minimapa.get(3).getDistancias().add(97);
        minimapa.get(3).getDistancias().add(98);

        minimapa.get(4).getDistancias().add(100);

        minimapa.get(5).getDistancias().add(98);

        minimapa.get(6).getDistancias().add(50);

        minimapa.get(9).getDistancias().add(115);

        minimapa.get(10).getDistancias().add(67);

        minimapa.get(11).getDistancias().add(160);

        minimapa.get(12).getDistancias().add(55);
        minimapa.get(12).getDistancias().add(103);

        minimapa.get(13).getDistancias().add(122);
        minimapa.get(13).getDistancias().add(58);
        minimapa.get(13).getDistancias().add(97);

        minimapa.get(14).getDistancias().add(97);
        minimapa.get(14).getDistancias().add(75);
        minimapa.get(14).getDistancias().add(100);

        minimapa.get(15).getDistancias().add(99);
        minimapa.get(15).getDistancias().add(75);
        minimapa.get(15).getDistancias().add(78);
        minimapa.get(15).getDistancias().add(105);

        minimapa.get(16).getDistancias().add(52);
        minimapa.get(16).getDistancias().add(180);
        minimapa.get(16).getDistancias().add(67);

        minimapa.get(17).getDistancias().add(54);
        minimapa.get(17).getDistancias().add(182);
        minimapa.get(17).getDistancias().add(53);
        minimapa.get(17).getDistancias().add(180);

        minimapa.get(18).getDistancias().add(184);
        minimapa.get(18).getDistancias().add(55);
        minimapa.get(18).getDistancias().add(61);
        minimapa.get(18).getDistancias().add(53);

        minimapa.get(19).getDistancias().add(67);
        minimapa.get(19).getDistancias().add(100);

        minimapa.get(20).getDistancias().add(112);
        minimapa.get(20).getDistancias().add(108);

        minimapa.get(21).getDistancias().add(120);
        minimapa.get(21).getDistancias().add(144);
        minimapa.get(21).getDistancias().add(83);

        minimapa.get(22).getDistancias().add(83);
        minimapa.get(22).getDistancias().add(66);
        minimapa.get(22).getDistancias().add(180);

        minimapa.get(23).getDistancias().add(180);
        minimapa.get(23).getDistancias().add(54);
        minimapa.get(23).getDistancias().add(52);
        minimapa.get(23).getDistancias().add(182);

        minimapa.get(24).getDistancias().add(182);
        minimapa.get(24).getDistancias().add(68);
        minimapa.get(24).getDistancias().add(100);
        minimapa.get(24).getDistancias().add(82);

        minimapa.get(25).getDistancias().add(70);
        minimapa.get(25).getDistancias().add(182);

        minimapa.get(26).getDistancias().add(182);
        minimapa.get(26).getDistancias().add(68);
        minimapa.get(26).getDistancias().add(70);
        minimapa.get(26).getDistancias().add(78);

        minimapa.get(27).getDistancias().add(82);
        minimapa.get(27).getDistancias().add(130);
        minimapa.get(27).getDistancias().add(88);

        minimapa.get(28).getDistancias().add(180);
        minimapa.get(28).getDistancias().add(70);

        minimapa.get(29).getDistancias().add(180);
        minimapa.get(29).getDistancias().add(70);
        minimapa.get(29).getDistancias().add(80);
        minimapa.get(29).getDistancias().add(66);

        minimapa.get(30).getDistancias().add(80);
        minimapa.get(30).getDistancias().add(185);
        minimapa.get(30).getDistancias().add(88);

        minimapa.get(31).getDistancias().add(54);
        minimapa.get(31).getDistancias().add(179);

        minimapa.get(33).getDistancias().add(150);

        minimapa.get(34).getDistancias().add(65);
        minimapa.get(34).getDistancias().add(75);

        minimapa.get(35).getDistancias().add(130);
        minimapa.get(35).getDistancias().add(78);

        minimapa.get(36).getDistancias().add(130);
        minimapa.get(36).getDistancias().add(87);

        minimapa.get(37).getDistancias().add(90);

        minimapa.get(38).getDistancias().add(30);

        minimapa.get(39).getDistancias().add(115);

        minimapa.get(40).getDistancias().add(70);
        minimapa.get(40).getDistancias().add(138);

        //Añdir Ubicacion de las calles paralelas a los nodos
        minimapa.get(0).getUbicacion().add(AvNutibara);
        minimapa.get(1).getUbicacion().add(AvNutibara);
        minimapa.get(2).getUbicacion().add(AvNutibara);
        minimapa.get(3).getUbicacion().add(AvNutibara);
        minimapa.get(4).getUbicacion().add(AvNutibara);
        minimapa.get(5).getUbicacion().add(AvNutibara);
        minimapa.get(6).getUbicacion().add(AvNutibara);

        minimapa.get(7).getUbicacion().add(Transv39a);
        minimapa.get(8).getUbicacion().add(Transv39a);
        minimapa.get(9).getUbicacion().add(Transv39a);
        minimapa.get(10).getUbicacion().add(Transv39a);

        minimapa.get(11).getUbicacion().add(Transv39);
        minimapa.get(12).getUbicacion().add(Transv39);
        minimapa.get(13).getUbicacion().add(Transv39);
        minimapa.get(14).getUbicacion().add(Transv39);
        minimapa.get(15).getUbicacion().add(Transv39);
        minimapa.get(16).getUbicacion().add(Transv39);
        minimapa.get(17).getUbicacion().add(Transv39);
        minimapa.get(18).getUbicacion().add(Transv39);
        minimapa.get(19).getUbicacion().add(Transv39);

        minimapa.get(20).getUbicacion().add(Transv38);
        minimapa.get(21).getUbicacion().add(Transv38);
        minimapa.get(22).getUbicacion().add(Transv38);
        minimapa.get(23).getUbicacion().add(Transv38);
        minimapa.get(24).getUbicacion().add(Transv38);

        minimapa.get(25).getUbicacion().add(Transv37);
        minimapa.get(26).getUbicacion().add(Transv37);
        minimapa.get(27).getUbicacion().add(Transv37);

        minimapa.get(28).getUbicacion().add(Transv36);
        minimapa.get(29).getUbicacion().add(Transv36);
        minimapa.get(30).getUbicacion().add(Transv36);

        minimapa.get(31).getUbicacion().add(Transv35);
        minimapa.get(32).getUbicacion().add(Transv35);

        minimapa.get(38).getUbicacion().add(Transv34);
        minimapa.get(40).getUbicacion().add(Transv34);

        minimapa.get(11).getUbicacion().add(Carrera36);
        minimapa.get(33).getUbicacion().add(Carrera36);
        minimapa.get(34).getUbicacion().add(Carrera36);
        minimapa.get(35).getUbicacion().add(Carrera36);
        minimapa.get(36).getUbicacion().add(Carrera36);
        minimapa.get(37).getUbicacion().add(Carrera36);
        minimapa.get(38).getUbicacion().add(Carrera36);
        minimapa.get(39).getUbicacion().add(Carrera36);
        
        

        //Calles perpendiculares

        minimapa.get(0).getUbicacion().add(Transv39cb);
        minimapa.get(12).getUbicacion().add(Transv39cb);

        minimapa.get(1).getUbicacion().add(Transv39ca);
        minimapa.get(13).getUbicacion().add(Transv39ca);

        minimapa.get(2).getUbicacion().add(Circ73b);
        minimapa.get(14).getUbicacion().add(Circ73b);
        minimapa.get(20).getUbicacion().add(Circ73b);
        minimapa.get(34).getUbicacion().add(Circ73b);

        minimapa.get(3).getUbicacion().add(Circ73a);
        minimapa.get(15).getUbicacion().add(Circ73a);
        minimapa.get(21).getUbicacion().add(Circ73a);

        minimapa.get(4).getUbicacion().add(Circ73);
        minimapa.get(16).getUbicacion().add(Circ73);
        minimapa.get(7).getUbicacion().add(Circ73);
        minimapa.get(22).getUbicacion().add(Circ73);
        minimapa.get(25).getUbicacion().add(Circ73);
        minimapa.get(28).getUbicacion().add(Circ73);
        minimapa.get(31).getUbicacion().add(Circ73);
        minimapa.get(37).getUbicacion().add(Circ73);

        minimapa.get(5).getUbicacion().add(Circ72);
        minimapa.get(8).getUbicacion().add(Circ72);
        minimapa.get(17).getUbicacion().add(Circ72);
        minimapa.get(23).getUbicacion().add(Circ72);
        minimapa.get(26).getUbicacion().add(Circ72);
        minimapa.get(29).getUbicacion().add(Circ72);
        minimapa.get(32).getUbicacion().add(Circ72);

        minimapa.get(6).getUbicacion().add(Circ71);
        minimapa.get(9).getUbicacion().add(Circ71);
        minimapa.get(18).getUbicacion().add(Circ71);
        minimapa.get(24).getUbicacion().add(Circ71);

        minimapa.get(10).getUbicacion().add(Clle33a);
        minimapa.get(19).getUbicacion().add(Clle33a);
        minimapa.get(24).getUbicacion().add(Clle33a);
        minimapa.get(27).getUbicacion().add(Clle33a);
        minimapa.get(30).getUbicacion().add(Clle33a);
        minimapa.get(40).getUbicacion().add(Clle33a);

        minimapa.get(21).getUbicacion().add(Clle35);
        minimapa.get(35).getUbicacion().add(Clle35);


        //Añadir calles al mapa
        mapa.add(AvNutibara);
        mapa.add(Transv39a);
        mapa.add(Transv39);
        mapa.add(Transv38);
        mapa.add(Transv37);
        mapa.add(Transv36);
        mapa.add(Transv35);
        mapa.add(Carrera36);

        mapa.add(Transv39cb);
        mapa.add(Transv39ca);
        mapa.add(Circ73b);
        mapa.add(Circ73a);
        mapa.add(Circ73);
        mapa.add(Circ72);
        mapa.add(Circ71);
        mapa.add(Clle33a);

        mapa.add(Clle35);




        // asignar metros entre nodos al diccionario
        HashMap<Nodo, HashMap<Nodo, Integer>> grafo = new HashMap<>();

        for (int i = 0; i < minimapa.size(); i++) {

            // obtiene un nodo del minimapa
            Nodo nodo = minimapa.get(i);

            // crea un hashmap para las distancias de ese nodo
            grafo.put(nodo, new HashMap<>());

            // asigna al nuevo hashmap el nodo vecino y los metros correspondientes
            for (int f = 0; f < nodo.getAdyacentes().size(); f++) {

                Nodo nodoAdyacente = nodo.getAdyacentes().get(f);
                int distancia = nodo.getDistancias().get(f);

                // devuelve un hashmap con la clave de la ciudad y le asigna el vecino y los
                // kilometros a esa ciudad
                grafo.get(nodo).put(nodoAdyacente, distancia);

            }

        }



        //Añadir Nodos a Vías
        for(int i = 0; i < mapa.size(); i++){
            for(int j = 0; j < minimapa.size(); j++){
                if(minimapa.get(j).getUbicacion().contains(mapa.get(i))){
                    
                    mapa.get(i).getNodos().add(minimapa.get(j));
                }
            }
        }


        System.out.println("----------------------------------------------");
        

        //Testeo para ver si los nodos se han añadido correctamente a las vias
        for(int i = 0; i < mapa.size(); i++){
            System.out.print(mapa.get(i).getNombre() + ": ");

            for(int j = 0; j < mapa.get(i).getNodos().size(); j++){
                System.out.print(mapa.get(i).getNodos().get(j).getId() + " ");
            }
            System.out.println();
            System.out.println("----------------------------------------------");
        }


        //Encuentra todas las rutas desde el nodo 1 hasta el nodo 28

        ArrayList<ArrayList<Nodo>> rutas = BuscarRutas(minimapa.get(1), minimapa.get(28));


        // Organizar Rutas segun nodos

        if (opt == 1) {

           
            for (int i = 0; i < rutas.size(); i++) {
                for (int j = 0; j < rutas.size() - i - 1; j++) {

                    if (rutas.get(j).size() > rutas.get(j + 1).size()) {
                        Collections.swap(rutas, j, j + 1);
                    }
                }
            }

            System.out.println("---------------------------------------------------------------------");

            for(int i = 0; i < rutas.size(); i++){

                System.out.println("Ruta: " + i);
                for(int j = 0; j < rutas.get(i).size(); j++){
                    System.out.print(rutas.get(i).get(j).getId() + " ");
                }

                System.out.println();
                System.out.println("---------------------------------------------------------------------------------");
            }

        }

       
        //Segun Costo Rutas KM
        ArrayList<Integer> costoRutas = new ArrayList<>();

        if (opt == 2) {

            // Calcular costo rutas km

            for (int h = 0; h < rutas.size(); h++) {

                costoRutas.add(calcularCosto(rutas.get(h), grafo));
            }

            // Ordenar rutas segun el costo

            for (int i = 0; i < costoRutas.size(); i++) {
                for (int j = 0; j < costoRutas.size() - i - 1; j++) {

                    if (costoRutas.get(j) > costoRutas.get(j + 1)) {
                        Collections.swap(costoRutas, j, j + 1);
                        Collections.swap(rutas, j, j + 1);
                    }
                }
            }

            // Mostrar Rutas segun Km

            System.out.println("---------------------------------------------------------------------------------");

            for (int i = 0; i < rutas.size(); i++) {

                System.out.println("Ruta Num: " + i);
                for (int j = 0; j < rutas.get(i).size(); j++) {

                    System.out.print(" " + minimapa.indexOf(rutas.get(i).get(j)));
                }
                Double distanciaKm = ((double) costoRutas.get(i) / 1000);
                System.out.print("-> " + distanciaKm + " km");

                System.out.println();

                System.out.println("---------------------------------------------------------------------------------");
            }

        }
        

        ArrayList<Integer> giros = new ArrayList<>();

        if (opt == 3) {
            // contar giros

            

            for (int i = 0; i < rutas.size(); i++) {

                ArrayList<Nodo> rutaActual = rutas.get(i);

                int n = 0;//<- Contador de giros para la ruta actual

                boolean viaComun = false;

                for (int j = 0; j < rutaActual.size() - 2; j++) {

                    Nodo nodoActual = rutaActual.get(j);
                    Nodo nodoIntermedio = rutaActual.get(j+1);
                    Nodo nodoPosterior = rutaActual.get(j + 2);

                    viaComun = false;

                    for (int h = 0; h < nodoIntermedio.getUbicacion().size(); h++) { 

                        Via viaActual = nodoIntermedio.getUbicacion().get(h);

                        if(nodoActual.getUbicacion().contains(viaActual) && nodoPosterior.getUbicacion().contains(viaActual)){
                            viaComun= true;
                            break;
                        }
                    }

                    if(viaComun == false){
                        n++;
                    }

                }

                giros.add(n);

            }




            // Ordenar rutas segun los giros

            for (int i = 0; i < giros.size(); i++) {
                for (int j = 0; j < giros.size() - i - 1; j++) {

                    if (giros.get(j) > giros.get(j + 1)) {
                        Collections.swap(giros, j, j + 1);
                        Collections.swap(rutas, j, j + 1);
                    }
                }
            }

            //Mostrar Rutas segun giros
            System.out.println("---------------------------------------------------------------------------------");

            for (int i = 0; i < giros.size(); i++) {

                System.out.println("Ruta " + i + ", Giros: " + giros.get(i));

                for (int j = 0; j < rutas.get(i).size(); j++) {
                    System.out.print(rutas.get(i).get(j).getId() + " ");
                }
                System.out.println();
                System.out.println("---------------------------------------------------------------------------------");
            }
        }

        Scanner sc2 = new Scanner(System.in);
        int num;
        System.out.println("Ingrese la ruta que desea consultar: 0 - " + (rutas.size()-1));
        System.out.println("-1 para terminar");
        while(true){
            num = sc.nextInt();

            if(num == (-1)){
                break;
            }

            System.out.println("---------------------------------------------------------------------------------");
            System.out.println("Ruta Num: " + num);
            if(opt == 1){
                System.out.println("Nodos: "  + rutas.get(num).size());
            }
            if(opt == 2){
                Double distanciaKm = ((double) costoRutas.get(num) / 1000);
                System.out.println(distanciaKm + " km");
            }
            if(opt == 3){
                System.out.println("Giros: " + giros.get(num));
            }
            for(int i = 0; i < rutas.get(num).size(); i++){
                System.out.print(rutas.get(num).get(i).getId() + " ");
            }
            System.out.println();

        }

    }











    //funcion para buscar las rutas que devuelve lista
    public static ArrayList<ArrayList<Nodo>> BuscarRutas(Nodo inicio, Nodo destino){

        //crea la lista donde irá almacenando las rutas encontradas
        ArrayList<ArrayList<Nodo>> rutas = new ArrayList<>();

        //crea un arraylist que representa una ruta
        ArrayList<Nodo> ruta = new ArrayList<>();

        //agrega el nodo de inicio a la ruta (madrid)
        ruta.add(inicio);

        //empieza a iterar sobre los vecinos de madrid
        for(int i = 0; i < inicio.getAdyacentes().size(); i++){

            //obtiene un vecino
            Nodo actual = inicio.getAdyacentes().get(i);

            //para cada nodo genera una copia de la ruta actual
            ArrayList<Nodo> nuevaRuta = (ArrayList<Nodo>)ruta.clone();

            //agrega el vecino a la ruta
            nuevaRuta.add(actual);

            //invoca la función recursiva
            BuscarRuta(actual, destino, nuevaRuta, rutas);

        }

        return rutas;
    }

    //funcion recursiva
    public static void BuscarRuta(Nodo nodo, Nodo destino, ArrayList<Nodo> rutaActual, ArrayList<ArrayList<Nodo>> rutas){

        //compara si el nodo actual es el destino, si lo es significa que ha encontrado una ruta y la agrega a la lista externa
        if(nodo.equals(destino)){

            rutas.add(rutaActual);
            return;

        }else{

            //busca en los vecinos del nodo actual
           for(int i = 0; i < nodo.getAdyacentes().size(); i++){

                //temporal
                Nodo actual = nodo.getAdyacentes().get(i);

                //crea una copia de la ruta correspondiente al nodo "actual"
                ArrayList<Nodo> nuevaRuta = (ArrayList<Nodo>)rutaActual.clone();
                
                //verifica si el nodo actual ya está en la lista, evita repeticiones
                if(nuevaRuta.contains(actual) == false){

                    //agrega el nodo y busca nuevamente un vecino de este nodo
                    nuevaRuta.add(actual);
                    BuscarRuta(actual, destino, nuevaRuta, rutas);

                }

           }
        }


    }

    //funcion que calcula los kilometros de una ruta
    public static int calcularCosto(ArrayList<Nodo> ruta, HashMap<Nodo, HashMap<Nodo, Integer>> grafo){

        //inicia el contador
        int costo = 0;

        //recorre cada uno de los nodos de la ruta
        for (int i = 0; i < ruta.size() - 1; i++){

            ruta.get(i); // -> Ciudad Actual
            ruta.get(i + 1); //Ciudad Vecina

            //busca los kilometros entre los dos nodos en el grafo
            costo += grafo.get(ruta.get(i)).get(ruta.get(i + 1));

        }

        return costo;
    }

}
