declare module '@venobo/cerberus' {
	// @TODO: descriptions for methods and accessors
	export class CerberusPlayer {
		constructor(uri: string);

		mute: boolean;

		play(): boolean;
		stop(): void;
	}

	export class CerberusRenderer {}
}