package Education_system;

public abstract class ChangePassword {

    protected String file;

    public ChangePassword(String file) {
        this.file = file;
    }
    
    public abstract void changePassword(String file);
}
