class Solution {
private:
    string doc;
    stack<char> undoStack;
    stack<char> redoStack;

public:
    void append(char x) {
        doc.push_back(x);
        undoStack.push(x);
        
        // Once a new append happens, redo history is invalid
        while (!redoStack.empty())
            redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            char last = undoStack.top();
            undoStack.pop();
            doc.pop_back();
            redoStack.push(last);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            char last = redoStack.top();
            redoStack.pop();
            doc.push_back(last);
            undoStack.push(last);
        }
    }

    string read() {
        return doc;
    }
};
