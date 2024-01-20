import java.util.HashMap;
public class Equipamiento extends Item {
    private String tipo;
    private Integer str;

    private Integer  inte;

    public Equipamiento(String tipo, int str, int inte,char representacion,String nombre){
        super(representacion,nombre);
        this.tipo=tipo;
        this.str=str;
        this.inte=inte;

    }

    //setter y getters
    public String getTipo() {
        return tipo;
    }


    public int getStr() {
        return str;
    }


    public int getInte() {
        return inte;
    }


    public char getRepresentacion() {
        return super.getRepresentacion();
    }


}
