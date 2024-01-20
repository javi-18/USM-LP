public abstract class Item implements Visible{
    private char representacion;
    private String nombre;

    public Item(char representacion,String nombre){
        this.representacion=representacion;
        this.nombre=nombre;

    }
    //setters y getters
    public String getNombre_item() {
        return nombre;
    }

    public char getRepresentacion() {
        return representacion;
    }
    public void setRepresentacion(char representacion) {
        this.representacion = representacion;
    }

    public void setNombre_item(String nombre) {
        this.nombre = nombre;
    }
}
