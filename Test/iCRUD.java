import java.io.IOException;

public interface iCRUD {
    public Object createItem();
    public int addItem();
    public int updateItem();
    public int deleteItem();
    public int printItem();
    public int report();
    public int saveData()throws IOException;


}
