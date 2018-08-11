


#include "Ngen.hpp"




class Alarm {
public:
	typedef VoidStaticDelegate<Alarm*>::TFunction TTick;
	
	Alarm(uword rateInSeconds, TTick onTick) : Activated(), Deactivated(), Ticked(), 
				mIsActive(false), mRate(rateInSeconds), mRemaing(rateInSeconds) {
		Ticked += onTick;
		mCache.Add(this);
	}
	
	~Alarm() {
		mCache.Remove(this);
	}
	
	void Activate() {
		mIsActive = true;
		AlarmActivated.Fire(this);
	}
	
	void Deactivate() {
		mIsActive = false;
		AlarmDeactivated.Fire(this);
	}
	
	void Tick() {
		if(mIsActive) {
			auto now = Time::Now();
			uword span = now.Seconds() - mLastTick.Seconds();
			mRemaing -= span;
			
			if(mRemaing <= 0 || mRate == 0) {
				Ticked.Fire(this);
				mRemaing = mRate;
			}
		}
	}

	static uword Count() {
		return mCache.Count();
	}
	
	event Activated;
	event Deactivated;
	event Ticked;
	
	static void TickAll() {
		for(uword i = 0; i < mCache.Count(); ++i) {
			mCache.Begin(i)->Tick();
		}
	}
	
	static void ClearAll() {
		mCache.Clear();
	}
	
protected:
	bool mIsActive;
	uword mRate;
	uword mRemaing;
	timespan mLastTick;
	
	static Array<Alarm*> mCache;
};

Array<Alarm*> Alarm::mCache = Array<Alarm*>();


class Application {
public:
	Application(const string& identity) : mId(identity), mIsRunning(false), mIsPaused(false) {
	}
	
	void Initialize() {
		Initialized.Fire(this);
	}
	
	void Run(uword fps=0) {
		Initialize();
		
		mIsRunning = true;
		Started.Fire(this);

		while(mIsRunning) {
			if(!mIsPaused) {
				this->Update();
			}
		}
		
		Close();
	}
	
	virtual void Update() {
		Updated.Fire(this);
	}
	
	virtual void Close() {
		if(mIsRunning) {
			mIsRunning = false;
			Closed.Fire(this);
		}
	}
	
	event Started;
	event Closed;
	event Paused;
	event Updated;
	event Initialized;
	
protected:
	static Application* mCurrent;
	
	mirror mId;
	bool mIsRunning;
	bool mIsPaused;
};

class GraphicalApplication : public virtual Application {
public:
	GraphicalApplication(const string& name, CanvasCreationParams params) : Application(name), mWindow(), mCanvas(), mCCparams(params) {
		this->Initialized += &OnAppInitialized;
		this->Updated += &OnAppUpdated;
		this->Started += &OnAppStarted;
		this->Stopped += &OnAppStopped;
	}
	
	Window* Window() { return &mWindow; }
	Canvas* Canvas() { return &mCanvas; }
	const Window* Window() const { return &mWindow; }
	const Canvas* Canvas() const { return &mCanvas; }
	
protected:
	virtual void OnAppInitialized(Application* app) {
		mWindow = Window(0, 0, mCCparams.Width(), mCCparams.Height(), this->mName.ToString());
		mCanvas = Canvas(&window, mCCparams);
	}
	
	virtual void OnAppUpdated(Application* app) {		
		if(window.HandleMessage()) {
			canvas.Clear(mCCparams.BackgroundColor());
			canvas.Update();
		}
	}
	
	virtual void OnAppStarted(Application* app) {
		window.Show();
	}
	
	virtual void OnAppStopped(Application* app) {
		window.Close();
	}
	
	Window mWindow;
	Canvas mCanvas;
	CanvasCreationParams mCCparams;
};

void ngen_main() {
	auto app = Application::Current();
	
	// set off the alarms
	auto alarm_token = Thread.Start([] () { 
		while(app.IsRunnnig()) {
			if(Alarm::Count() != 0) {
				Alarm::TickAll();
			}
		}
	});
}

void on_keyboard_pressed(KeyboardEventArgs args) {
	if(args.Key == EKey::Escape) {
		args.Window()->Close();
	}
}

class Game : public virtual GraphicalApplication {
public:
	Game(const string& name, const CanvasCreationParams& params) : GraphicalApplication(name, params) {
		
	}
	
	Keyboard* Keyboard(uword index=0) {
		return this->mWindow.GetInputDevice("Keyboard", index);
	}
	
	Mouse* Mouse(uword index=0) {
		return this->mWindow.GetInputDevice("Mouse", index);
	}
	
	Gamepad* Gamepad(uword index=0) {
		return this->mWindow.GetInputDevice("Gamepad", index);
	}
	
protected:
	virtual override OnAppInitialized(Application* app) {
		GraphicalApplication::OnAppInitialized(app);
		
	}
};

int main() {
	auto app = MyApp();
	auto keyboard = app.Window->GetInputDevice("Keyboard", 0);
	auto mouse = app.Window->GetInputDevice("Mouse", 0);
	
	keyboard.KeyPress += &on_keyboard_pressed;
	ngen_main();
	app.Run();
}

