
import java.util.ArrayList;
import java.util.Random;
import java.util.List;

public class Mundo {
    private Integer nivel;
    private Integer alto;
    private Integer ancho;
    private Integer enemigos;
    private List<List<Visible>> mapa;

    private int pos_jugador_x;
    private int pos_jugador_y;
    private int fin = 1;
    private Jugador jugador;


    // getters y setters
    public int getPos_jugador_x() {
        return pos_jugador_x;
    }

    public int getPos_jugador_y() {
        return pos_jugador_y;
    }

    public Integer getNivel() {
        return nivel;
    }

    public Integer getEnemigos() {
        return enemigos;
    }

    public int getFin() {
        return fin;
    }

    //constructor
    public Mundo(int nivel, int alto, int ancho) {
        this.alto = alto;
        this.ancho = ancho;
        this.enemigos = 0;
        this.pos_jugador_x = 0;
        this.pos_jugador_y = 0;
        this.nivel = nivel;

    }

    /*
     * Funcion que permite crear el jugador son el nombre que el usuario ingrese por consola
     *
     * @String nombre: es objeto de tipo string, el cual representa el nombre que tendra el jugador
     *
     * @return : no retorna nada, pero permite crear el jugador con el nombre que el usuario ingrese
     * */
    public void crearjugador(String nombre) {
        float hp_inicial = 100;
        jugador = new Jugador(hp_inicial, 1);
        jugador.setNombre(nombre);
    }


    /*
     * Funcion que permite mostrar el iventario completo con las armas y equipamiento que tenga el jugador
     *
     * @ este metodo no recibe ningun parametro
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void mostrar_inventario() {
        System.out.println("---------------------------------------");
        for (int i = 0; i < jugador.getItems().size(); i++) {
            System.out.print((i + 1) + ")");
            System.out.println(jugador.getItems().get(i).getNombre_item());
            if (jugador.getItems().get(i) instanceof Arma) {
                Arma arma = (Arma) jugador.getItems().get(i);
                float dmg = arma.calcularAtaque(1, 1);
                System.out.println("Daño del arma: " + dmg);
            } else {
                Equipamiento equipables = (Equipamiento) jugador.getItems().get(i);
                Integer fuerza = equipables.getStr();
                Integer inteligencia = equipables.getInte();
                String type = equipables.getTipo();
                System.out.println("Inteligencia : " + inteligencia);
                System.out.println("Fuerza : " + fuerza);
                System.out.println("Tipo : " + type);
            }
            System.out.println("------------------------------------");

        }
    }

    /*
     * Funcion que permite mostrar el inventario de manera mas resumida respecto al metodo mostrar_inventario()
     *
     * @este metodo no recibe ningun parametro
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void ver_inventario_mini() {
        System.out.println("------------------------------------");
        for (int i = 0; i < jugador.getItems().size(); i++) {
            System.out.print((i + 1) + ")");
            System.out.println(jugador.getItems().get(i).getNombre_item());
        }
        System.out.println("------------------------------------");
    }


    /*
     * Funcion que permite mostrar las estadisticas del jugador en cualquier momento de la partida
     *
     * @este metodo no recibe ningun parametro
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void stats() {
        System.out.println("------------------------------------");
        System.out.println("Nombre: " + jugador.getNombre() + "      Nivel: " + jugador.getNivel() + "      Experiencia: " + jugador.getXp());
        System.out.println("Vida: " + jugador.getHp() + "            Danio: " + jugador.calcularAtaque());

        System.out.println(jugador.getArma().getNombre_item() + "     strength: " + jugador.getArma().getMult_str() + "     intelligence: " + jugador.getArma().getMult_int());
        if (jugador.getEquipamiento().get("Armadura") != null) {
            System.out.println("Armadura" + " : " + jugador.getEquipamiento().get("Armadura").getNombre_item());
        } else {
            System.out.println("Sin armadura");
        }
        if (jugador.getEquipamiento().get("Botas") != null) {
            System.out.println("Botas" + " : " + jugador.getEquipamiento().get("Botas"));
        } else {
            System.out.println("Sin botas");
        }
        if (jugador.getEquipamiento().get("Amuleto") != null) {
            System.out.println("Amuleto" + " : " + jugador.getEquipamiento().get("Amuleto").getNombre_item());
        } else {
            System.out.println("Sin amuleto");
        }

        System.out.println("------------------------------------");
    }


    /*
     * Funcion que permite mostrar al jugador equiparse un arma cuando este interacciona con una casilla item que
     * representa el arma
     *
     * @int opcion: es un dato de tipo entero que representa la posicion del item seleccionado en el inventario del personaje
     *
     * @return :  no retorna nada, solamente permite al jugador equipar el arma o equipamiento que se encuentre dentro del mapa
     * */
    public void equiparse(int opcion) {
        opcion -= 1;
        if (jugador.getItems().get(opcion) instanceof Arma) {
            Arma arma = (Arma) jugador.getItems().get(opcion);
            jugador.equipar(arma);
            System.out.println(jugador.getArma().getNombre_item() + " ha sido equipada");
        } else {
            Equipamiento equipar = (Equipamiento) jugador.getItems().get(opcion);
            jugador.equipar(equipar);

        }

    }


    /*
     * Funcion que permite mostrar el mapa con todos los elementos como jugador, enemigos e items creados
     *
     * @este metodo no recibe parametros
     *
     * @return : no retorna nada
     * */
    public void mostrar() {
        for (List<Visible> fila : mapa) {
            for (Visible rep : fila) {
                System.out.print("[" + rep.getRepresentacion() + "]");
            }
            System.out.println();
        }
    }


    /*
     * Funcion que aumenta el nivel del mapa
     *
     * @ no recibe parametros
     *
     * como es un metodo void, no devuelve nada
     *
     *
     * */
    public void nuevoNivel() {
        nivel++;
        pos_jugador_x = 0;
        pos_jugador_y = 0;
        enemigos = 0;
        generarMapa();

    }


    /*
     * Funcion que permite crear  el mapa con todos los elementos como jugador, enemigos e items creados
     *
     * @no tiene parametros
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void generarMapa() {
        Random random = new Random();
        Double r;
        Double min_item;
        Double min_enemigo;
        float stat_arm;
        Integer str;
        Integer inte;

        mapa = new ArrayList<List<Visible>>();
        for (int i = 0; i < alto; i++) {
            List<Visible> fila = new ArrayList<Visible>();
            for (int j = 0; j < ancho; j++) {
                if (i == 0 && j == 0) {
                    jugador.setHp(jugador.getHp() + 50 + 5 * nivel);
                    fila.add(jugador);
                } else {
                    r = random.nextDouble();
                    min_item = Math.min(0.05 + 0.01 * getNivel(), 20.0);
                    min_enemigo = Math.min(0.2 + 0.01 * getNivel(), 55.0);

                    if (r <= min_item) {
                        stat_arm = 2;
                        r = random.nextDouble();
                        if (r <= 0.5) {
                            Arma arma = new Arma(2, 2, 'A', "Espada de caballero");
                            fila.add(arma);
                        } else {
                            str = 3;
                            inte = 4;
                            Equipamiento equipamiento = new Equipamiento("Espada de caballero", str, inte, 'E', "Armadura de asalto");
                            fila.add(equipamiento);
                        }


                    } else if (min_item<r && r < min_enemigo) {
                        stat_arm = 100;
                        enemigos++;
                        Personaje enemy = new Personaje(stat_arm, 100);
                        fila.add(enemy);

                    } else {
                        Vacia vacia = new Vacia('_');
                        fila.add(vacia);
                    }
                }

            }
            mapa.add(fila);

        }
    }






    /*
     * Funcion que permite mover al jugador dentro del mapa, ademas de interactuar con cada casilla que este se encuentre
     * @int nuevo_x: es un entero que representa a la nueva coordenada x del jugador
     * @int nuevo_y: es un entero que representa a la nueva coordenada y del jugador
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void moverJugador(int coordx, int coordy) {
        if (0 <= coordx && coordx < ancho.intValue() && 0 <= coordy && coordy < alto.intValue()) {
            Visible destino = mapa.get(coordy).get(coordx);
            Jugador jugador = (Jugador) mapa.get(pos_jugador_y).get(pos_jugador_x);


            if (destino instanceof Arma) {
                jugador.agregar_inventario(mapa.get(coordy).get(coordx));
                Vacia vacio = new Vacia(' ');
                mapa.get(coordy).set(coordx, vacio);
                pos_jugador_y = coordy;
                pos_jugador_x = coordx;

            } else if (destino instanceof Equipamiento) {
                jugador.agregar_inventario(mapa.get(coordy).get(coordx));
                Vacia vacio = new Vacia(' ');
                mapa.get(coordy).set(coordx, jugador);
                mapa.get(pos_jugador_y).set(pos_jugador_x, vacio);
                pos_jugador_y = coordy;
                pos_jugador_x = coordx;
            } else if (destino instanceof Personaje) {

                System.out.println("Te has encontrado a un enemigo D: .");
                Personaje enemigo = (Personaje) destino;
                while (jugador.getHp() > 0 && enemigo.getHp() > 0) {
                    System.out.println("O " + "<---(-" + jugador.calcularAtaque() + ")---" + "  J");
                    enemigo.recibirDanio(jugador.calcularAtaque());
                    if (enemigo.getHp() <= 0) {
                        System.out.println("HP enemigo: 0");
                        System.out.println(jugador.getNombre() + "HP: " + jugador.getHp());
                        break;
                    }
                    System.out.println("O " + "---(-" + jugador.calcularAtaque() + ")--->" + "  J");
                    jugador.recibirDanio(enemigo.calcularAtaque());
                    if (jugador.getHp() <= 0) {
                        System.out.println("HP enemigo: " + enemigo.getHp());
                        System.out.println(jugador.getNombre() + "HP:0");
                        break;

                    }


                }

                if (jugador.getHp() > 0) {
                    Vacia vacia = new Vacia(' ');
                    mapa.get(coordy).set(coordx, jugador);
                    mapa.get(pos_jugador_y).set(pos_jugador_x, vacia);
                    pos_jugador_y = coordy;
                    pos_jugador_x = coordx;
                    enemigos--;
                    jugador.ganarXP(40);

                } else {
                    System.out.println("-------Game Over-------");
                    fin = 0;
                }


            } else {
                Vacia vacio = new Vacia(' ');
                mapa.get(coordy).set(coordx, jugador);
                mapa.get(pos_jugador_y).set(pos_jugador_x, vacio);
                pos_jugador_y = coordy;
                pos_jugador_x = coordx;
            }
        }


    }
}

