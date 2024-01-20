import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Jugador extends Personaje{
    public String nombre;
    private Integer xp;
    private List<Item>items;

    private int x;
    private int y;

    private Map<String, Equipamiento> equipamiento;

    private Arma arma;

    public Jugador(Float hp, Integer nivel) {
        super(hp, nivel);
        this.xp=0;
        this.items=new ArrayList<Item>();
        this.equipamiento=new HashMap<>();
        this.arma=new Arma(0.5f,0.25f,'s',"Espada basica");
    }

//setters y getters
    public char getRepresentacion() {
        return 'J';
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }


    public List<Item> getItems() {
        return items;
    }

    public Integer getXp() {
        return xp;
    }

    public Arma getArma() {
        return arma;
    }

    public Map<String, Equipamiento> getEquipamiento() {
        return equipamiento;
    }




    /*
     * Funcion que aumentar la experiencia del jugador luego de un combate
     *
     * @Integer puntos_xp: objeto de tipo Integer que representa los puntos de experiencia obtenidos luego de que el
     * jugdor entro en batalla
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void ganarXP(Integer puntos_xp){
        xp+=puntos_xp;
        if (xp>=100){
            subirNivel();
        }
    }


    /*
     * Funcion que permite subir de nivel al jugador
     *
     * @no recibe ningun parametro
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    private void subirNivel(){
        setNivel(getNivel()+1);
        xp-=100;
    }



    /*
     * Funcion que permite calcular la cantidad de daño que hace el jugador al atacar
     *
     * @no recibe ningun parametro
     *
     * @return : esta funcion retorna el daño total que el jugador realiza
     * */
    public float calcularAtaque(){
        int str_equip=0;
        int inte_equip=0;

        if(equipamiento.get("Armadura") != null){
            str_equip+=equipamiento.get("Armadura").getStr();
            inte_equip+=equipamiento.get("Armadura").getInte();
        }
        if(equipamiento.get("Botas") != null){
            str_equip+=equipamiento.get("Botas").getStr();
            inte_equip+=equipamiento.get("Botas").getInte();
        }
        if(equipamiento.get("Amuleto") != null){
            str_equip+=equipamiento.get("Amuleto").getStr();
            inte_equip+=equipamiento.get("Amuleto").getInte();
        }
        return 3*getNivel() + arma.calcularAtaque(str_equip, inte_equip);
    }



    /*
     * Funcion que permite al jugador equipar un arma que encuentre dentro del mapa, sabiendo su nombre y estadisticas
     *
     * @Arma arma: es un objeto de tipo Arma que presenta sus estadisticas y nombre
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void equipar(Arma arma) {
        this.arma.setNombre_item(arma.getNombre_item());
        this.arma.setMult_str(arma.getMult_str());
        this.arma.setMult_int(arma.getMult_int());
        this.arma.setRepresentacion((arma.getRepresentacion()));
    }


    /*
     * Funcion que permite equipar un nuevo equipamiento de distinto tipo que se encuentra dentro del mapa
     *
     * @Equipamiento new_equipamiento: es un objeto de tipo Equipamiento el cual puede representar un armadura,botas o
     * amuleto
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void equipar(Equipamiento new_equipamiento){
        this.equipamiento.put(new_equipamiento.getTipo(),new_equipamiento);
    }


    /*
     * Funcion que permite agregar un item cualquiera que el jugador que se encuentre dentro del mapa en el inventario
     *
     * @Visible item_rec: es un objeto de tipo Visible que representa el caracter del item encontrado,el cual puede ser
     * 'A' de arma, 'E' de equipamiento, etc
     *
     * @return : Como es un metodo void, entonces no retorna nada
     * */
    public void agregar_inventario(Visible item_rec){
        Item item=(Item)item_rec;
        items.add(item);
    }

}

